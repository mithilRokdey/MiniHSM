#pragma once

namespace minihsm {
class IModule {
public:
  virtual ~IModule() = default;
  virtual bool initialize() = 0;
  virtual void shutdown() = 0;
};
} // namespace minihsm
