//===----------------------------------------------------------------------===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "npcomp/InitAll.h"

#include "mlir/IR/Dialect.h"
#include "npcomp/Backend/Common/Passes.h"
#include "npcomp/Conversion/Passes.h"
#include "npcomp/Dialect/TorchConversion/IR/TorchConversionDialect.h"
#include "npcomp/Dialect/TorchConversion/Transforms/Passes.h"

void mlir::NPCOMP::registerAllDialects(mlir::DialectRegistry &registry) {
  registry.insert<mlir::NPCOMP::TorchConversion::TorchConversionDialect>();
}

void mlir::NPCOMP::registerAllPasses() {
  mlir::NPCOMP::registerConversionPasses();
  mlir::NPCOMP::registerTorchConversionPasses();
  mlir::NPCOMP::CommonBackend::registerCommonBackendPasses();
}
