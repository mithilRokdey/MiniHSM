#pragma once

#include <string>

namespace minihsm {
struct RequestContext {
  std::string requestId;
  std::string userId;
  std::string operation;
};
} // namespace minihsm
