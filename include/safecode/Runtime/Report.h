//===- Report.h -------------------------------------------------*- C++ -*-===//
// 
//                       The SAFECode Compiler Project
//
// This file was developed by the LLVM research group and is distributed under
// the University of Illinois Open Source License. See LICENSE.TXT for details.
// 
//===----------------------------------------------------------------------===//
//
// This file define the interfaces for reporting memory safety violation found
// by SAFECode.
// Implemenation can inherit from ViolationInfo to store more information.
//
//===----------------------------------------------------------------------===//

#ifndef _REPORT_H_
#define _REPORT_H_

#include "safecode/SAFECode.h"

#include <iosfwd>

NAMESPACE_SC_BEGIN

struct ViolationInfo {
  enum {
    FAULT_DANGLING_PTR,
    FAULT_DOUBLE_FREE,
    FAULT_OUT_OF_BOUNDS
  };
  /// Tyep of violation
  unsigned int type;
  /// The program counter of the instruction generating the violations
  const void * faultPC;
  /// The pointer generating the violations
  const void * faultPtr;
  virtual void print(std::ostream & OS) const;
  virtual ~ViolationInfo();
};


//
// Function: ReportMemoryViolation()
//
// Description:
//  Report a memory violation
//
void
ReportMemoryViolation (const ViolationInfo * info);

NAMESPACE_SC_END

#endif