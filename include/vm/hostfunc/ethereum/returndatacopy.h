// SPDX-License-Identifier: Apache-2.0
#pragma once

#include "eei.h"

namespace SSVM {
namespace Executor {

class EEIReturnDataCopy : public EEI {
public:
  EEIReturnDataCopy(VM::EVMEnvironment &Env, uint64_t Cost = 100);
  EEIReturnDataCopy() = delete;
  virtual ~EEIReturnDataCopy() = default;

  virtual ErrCode run(VM::EnvironmentManager &EnvMgr, std::vector<Value> &Args,
                      std::vector<Value> &Res, StoreManager &Store,
                      Instance::ModuleInstance *ModInst);
};

} // namespace Executor
} // namespace SSVM
