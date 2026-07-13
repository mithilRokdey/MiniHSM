#pragma once

#include "IModule.hpp"

namespace minihsm {
class ExecutionManager : public IModule {
public:
  ExecutionManager();
  bool initialize() override;
  void shutdown() override;
};
} // namespace minihsm
