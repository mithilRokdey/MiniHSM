#include "ExecutionManager.hpp"

namespace minihsm {
ExecutionManager::ExecutionManager() = default;

bool ExecutionManager::initialize() {
  return true;
}

void ExecutionManager::shutdown() {
}
} // namespace minihsm
