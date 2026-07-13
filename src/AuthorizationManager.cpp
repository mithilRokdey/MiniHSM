#include "AuthorizationManager.hpp"

namespace minihsm {
AuthorizationManager::AuthorizationManager() = default;

bool AuthorizationManager::initialize() {
  return true;
}

void AuthorizationManager::shutdown() {
}
} // namespace minihsm
