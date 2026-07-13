#include "KeyManager.hpp"

namespace minihsm {
KeyManager::KeyManager() = default;

bool KeyManager::initialize() {
  return true;
}

void KeyManager::shutdown() {
}
} // namespace minihsm
