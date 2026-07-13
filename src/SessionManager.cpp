#include "SessionManager.hpp"

namespace minihsm {
SessionManager::SessionManager() = default;

bool SessionManager::initialize() {
  return true;
}

void SessionManager::shutdown() {
}
} // namespace minihsm
