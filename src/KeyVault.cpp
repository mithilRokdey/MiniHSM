#include "KeyVault.hpp"

namespace minihsm {
KeyVault::KeyVault() = default;

bool KeyVault::initialize() {
  return true;
}

void KeyVault::shutdown() {
}
} // namespace minihsm
