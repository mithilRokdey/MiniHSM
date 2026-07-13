#include "PolicyEngine.hpp"

namespace minihsm {
PolicyEngine::PolicyEngine() = default;

bool PolicyEngine::initialize() {
  return true;
}

void PolicyEngine::shutdown() {
}
} // namespace minihsm
