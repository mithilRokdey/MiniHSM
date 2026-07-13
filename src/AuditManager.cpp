#include "AuditManager.hpp"

namespace minihsm {
AuditManager::AuditManager() = default;

bool AuditManager::initialize() {
  return true;
}

void AuditManager::shutdown() {
}
} // namespace minihsm
