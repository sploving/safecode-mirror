#include "adl_splay.h"

#ifndef USE_RB

#include "safecode/Runtime/PoolSystem.h"

#define DEBUG(FORMAT, ...) do { \
  pthread_t id = pthread_self(); \
  fprintf(stderr, "tid:%d " FORMAT, id, __VA_ARGS__); \
  } while (0);
#undef DEBUG

#ifdef DEBUG
#include <stdio.h>
#include <pthread.h>
#else
#define DEBUG(FORMAT, ...) 
#endif

// #define ENABLE_SPLAY_TREE_TAG

typedef struct tree_node Tree;
struct tree_node {
  Tree* left;
  Tree* right;
  char* key;
  char* end;
#ifdef ENABLE_SPLAY_TREE_TAG
  void* tag;
#endif
};

/* Memory management functions */

static Tree* freelist = 0;
static void* (*ext_alloc)(unsigned) = poolcheckmalloc;
unsigned int externallocs = 0;
unsigned int allallocs = 0;

static Tree initmem[1024];
static int use = 0;

void *
internal_malloc (unsigned int size)
{
  static unsigned char * page = 0;
  static unsigned char * loc = 0;
  unsigned char * retvalue;

  if (size > 4096)
    poolcheckfatal ("LLVA: internal_malloc: Size", size);

  /*
   * Allocate a new page if we've never had a page or there isn't any room
   * in the current page.
   */
  if (!page)
  {
    loc = page = ext_alloc (2);
    ++externallocs;
  }

  if ((loc+size) > (page + 16384))
  {
    loc = page = ext_alloc (2);
    ++externallocs;
  }

  /*
   * Allocate the space and return a pointer to it.
   */
  retvalue = loc;
  loc += size;
  return retvalue;
}

static inline Tree* tmalloc() {
  ++allallocs;
  if(freelist) {
    Tree* t = freelist;
    freelist = freelist->left;
    return t;
  } else if(use < 1024) {
    ++use;
    return &initmem[use-1];
  } else {
    Tree * tmp = internal_malloc(sizeof(Tree));
    if (!tmp)
      poolcheckfatal ("LLVA: tmalloc: Failed to allocate", externallocs);
    return (Tree*) tmp;
  }
}

static inline void tfree(Tree* t) {
  t->left = freelist;
  freelist = t;
}


#define key_lt(_key, _t) (((char*)_key < (char*)_t->key))

#define key_gt(_key, _t) (((char*)_key > (char*)_t->end))


static inline Tree* rotate_right(Tree* p) {
  Tree* x = p->left;
  p->left = x->right;
  x->right = p;
  return x;
}

static inline Tree* rotate_left(Tree* p) {
  Tree* x = p->right;
  p->right = x->left;
  x->left = p;
  return x;
}

/* This function by D. Sleator <sleator@cs.cmu.edu> */
static Tree* splay (Tree * t, char* key) {
  Tree N, *l, *r, *y;
  if (t == 0) return t;
  N.left = N.right = 0;
  l = r = &N;

  while(1) {
    if (key_lt(key, t)) {
      if (t->left == 0) break;
      if (key_lt(key, t->left)) {
        y = t->left;                           /* rotate right */
        t->left = y->right;
        y->right = t;
        t = y;
        if (t->left == 0) break;
      }
      r->left = t;                               /* link right */
      r = t;
      t = t->left;
    } else if (key_gt(key, t)) {
      if (t->right == 0) break;
      if (key_gt(key, t->right)) {
        y = t->right;                          /* rotate left */
        t->right = y->left;
        y->left = t;
        t = y;
        if (t->right == 0) break;
      }
      l->right = t;                              /* link left */
      l = t;
      t = t->right;
    } else {
      break;
    }
  }
  l->right = t->left;                                /* assemble */
  r->left = t->right;
  t->left = N.right;
  t->right = N.left;
  return t;
}

static inline Tree* splay2 (Tree * t, char* key) { 
//inline version of splay
  Tree N, *l, *r, *y;
  if (t == 0) return t;
  N.left = N.right = 0;
  l = r = &N;
  while(1) {
    if (key_lt(key, t)) {
      if (t->left == 0) break;
      if (key_lt(key, t->left)) {
        y = t->left;                           /* rotate right */
        t->left = y->right;
        y->right = t;
        t = y;
        if (t->left == 0) break;
      }
      r->left = t;                               /* link right */
      r = t;
      t = t->left;
    } else if (key_gt(key, t)) {
      if (t->right == 0) break;
      if (key_gt(key, t->right)) {
        y = t->right;                          /* rotate left */
        t->right = y->left;
        y->left = t;
        t = y;
        if (t->right == 0) break;
      }
      l->right = t;                              /* link left */
      l = t;
      t = t->right;
    } else {
        break;
    }
  }
  l->right = t->left;                                /* assemble */
  r->left = t->right;
  t->left = N.right;
  t->right = N.left;
  return t;
}

/* My version, needs testing */
static Tree* my_splay(Tree* t, char* key) {
  if (!t) return t;
  
  while (1) {
    if (key_lt(key, t)) {
      if (!t->left) return t;
      else if (key_lt(key, t->left))
        t = rotate_right(rotate_right(t));
      else if (key_gt(key, t->left)) {
        t->left = rotate_left(t->left);
        t = rotate_right(t);
      } else
        return  rotate_right(t);
    } else if (key_gt(key, t)) {
      if (!t->right) return t;
      else if (key_gt(key, t->right))
        t = rotate_left(rotate_left(t));
      else if (key_lt(key, t->right)) {
        t->right = rotate_right(t->right);
        t = rotate_left(t);
      } else
        return rotate_left(t);
    } else
      return t;
  }
}

static inline Tree* insert(Tree* t, char* key, unsigned len, void* tag) {
  Tree* n = 0;
  t = splay(t, key);
  if (t && !key_lt(key, t) && !key_gt(key, t)) {
    /* already in, so update the record.  This could break
       the tree */
    t->key =  key;
    t->end = t->key + (len - 1);
#ifdef ENABLE_SPLAY_TREE_TAG
    t->tag = tag;
#endif
    return t;
  }
  n = tmalloc();
  n->key = key;
  n->end = key + (len - 1);
#ifdef ENABLE_SPLAY_TREE_TAG
  n->tag = tag;
#endif
  n->right = n->left = 0;
  if (t) {
    if (key_lt(key, t)) {
      n->left = t->left;
      n->right = t;
      t->left = 0;
    } else {
      n->right = t->right;
      n->left = t;
      t->right = 0;
    }
  }
  return n;
}

static inline Tree* delete(Tree* t, char* key) {
  if (!t) return t;
  t = splay(t, key);
  if (!key_lt(key, t) && !key_gt(key, t)) {
    Tree* x = 0;
    if (!t->left)
      x = t->right;
    else {
      x = splay(t->left, key);
      x->right = t->right;
    }
    tfree(t);
    return x;
  }
  return t; /* not there */
}


static int count(Tree* t) {
  if (t)
    return 1 + count(t->left) + count(t->right);
  return 0;
}

/* return any node with the matching tag */
static Tree* find_tag(Tree* t, void* tag) {
#ifdef ENABLE_SPLAY_TREE_TAG
  if (t) {
    Tree* n = 0;
    if (t->tag == tag) return t;
    if ((n = find_tag(t->left, tag))) return n;
    if ((n = find_tag(t->right, tag))) return n;
  }
#endif
  return 0;
}

/* interface */

void adl_splay_insert(void** tree, void* key, unsigned len, void* tag)
{
  DEBUG("adl_splay_insert:%p/%p/0x%x\n", tree, key, len)
  *(Tree**)tree = insert(*(Tree**)tree, (char*)key, len, tag);
}

void adl_splay_delete(void** tree, void* key)
{
  DEBUG("adl_splay_delete:%p/%p\n", tree, key)
  *(Tree**)tree = delete(*(Tree**)tree, (char*)key);
}

void adl_splay_delete_tag(void** tree, void* tag) {
  Tree* t = *(Tree**)tree;
  Tree* n = find_tag(t, tag);
  while (n) {
    DEBUG("adl_splay_delete_tag:%p/%p\n", t, n->key)
    t = delete(t, n->key);
    n = find_tag(t, tag);
  }
  *(Tree**)tree = t;
}

void adl_splay_clear(void** tree) {
  DEBUG("adl_splay_clear:%p/%p\n", *tree)
  Tree * n = adl_splay_any(tree);
  while(n) {
    Tree * t = delete(n, n->key);
    n = adl_splay_any(t);
  }
}

int  adl_splay_find(void** tree, void* key) {
  Tree* t = splay(*(Tree**)tree, (char*)key);
  *(Tree**)tree = t;
  return (t && 
          !key_lt(key, t) && 
          !key_gt(key, t));
}

/*
 * Function: adl_splay_lookup()
 *
 * Description:
 *  This function is an inlined version of the splay retrieve function.  It is
 *  called from boundscheckui_lookup() and can be inlined by the LLVM inliner.
 *
 * Outputs:
 *  key - The value pointed to by key is updated with the beginning address
 *        of the object.
 *
 * Return value:
 *  0 - The object was not found in the splay tree.
 *  Otherwise, the length of the object is returned.
 */
int
adl_splay_lookup (void** tree, void** key) {
  void* k = *key;
  Tree* t = splay2(*(Tree**)tree, (char*)k);
  *(Tree**)tree = t;
  
  if (t && !key_lt(k, t) && !key_gt(k, t)) {
    //The node exists in the splay tree
    *key = t->key;
    return (t->end - t->key) + 1;
  }

  return 0;
}

int adl_splay_retrieve(void** tree, void** key, unsigned* len, void** tag) {
  void* k = *key;
  Tree* t = splay(*(Tree**)tree, (char*)k);
  *(Tree**)tree = t;
  if (t && 
      !key_lt(k, t) && 
      !key_gt(k, t)) {
    *key = t->key;
    if (len) *len = (t->end - t->key) + 1;
#ifdef ENABLE_SPLAY_TREE_TAG
    if (tag) *tag = t->tag;
#endif
    DEBUG("adl_splay_retrieve: succ %p/%p/0x%x\n", *tree, *key, *len)
    return 1;
  }
  DEBUG("adl_splay_retrieve: failed %p/%p/0x%x\n", *tree, *key, *len)
  return 0;
}


int  adl_splay_size(void** tree) {
  return (count(*(Tree**)tree));
}

void* adl_splay_any(void** tree) {
  if (*(Tree**)tree)
    return ((*(Tree**)tree)->key);
  return 0;
}

void adl_splay_libinit(void* (nodealloc)(unsigned) ) {
  ext_alloc = nodealloc;
}

void adl_splay_libfini(void (nodefree)(void*) ) {
  while (freelist) {
    Tree* n = freelist->left;
    nodefree(freelist);
    freelist = n;
  }
}

void adl_splay_foreach(void** tree, void (f)(void*, unsigned, void*)) {
  Tree* T = *(Tree**)tree;
  if (T) {
#ifdef ENABLE_SPLAY_TREE_TAG
    f(T->key, (T->end - T->key) + 1, T->tag);
#else
    f(T->key, (T->end - T->key) + 1, 0);
#endif
    adl_splay_foreach(&T->left, f);
    adl_splay_foreach(&T->right, f);
  }
}


#ifdef TEST_TREE
#include <stdio.h>
#include <stdlib.h>

int main() {
  adl_splay_libinit((void* (*)(int))malloc);
  void* t = 0;
  long x;
  for (x = 0; x < 100; ++x) {
    adl_splay_insert(&t, (void*)x, 10, 0);
  }

  printf("Size after 100 inserts of size 10 (overlap): %d\n", adl_splay_size(&t));

  for (x = 0; x < 100; ++x) {
    int f = adl_splay_find(&t, (void*)x);
    if (!f) printf("Failed find!\n");
  }
  for (x = 0; x < 100; x += 20) {
    int f = adl_splay_find(&t, (void*)x);
    if (!f) printf("Failed find!\n");
  }

  for (x = 0; x < 100; ++x) {
    adl_splay_delete(&t, (void*)x);
  }

  printf("Size should be 0: %d\n", adl_splay_size(&t));
  return 0;
}

void poolcheckfatal (const char * msg, int x) {
  printf("%s %d\n", msg, x);
}


#endif

#endif
