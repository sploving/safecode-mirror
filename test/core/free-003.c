// RUN: test.sh -e -t %t %s
//
// TEST: free-001
//
// Description:
//  Test invalid memory deallocations
//

#include <stdio.h>
#include <stdlib.h>

char array[1024];

int
main (int argc, char ** argv) {
  free (&(array[5]));
  return 0;
}
