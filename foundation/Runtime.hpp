#pragma once
#include "Thread.hpp"
#include <array>
#include <cstdint>

namespace foundation {

/**
 * @brief Runtime/Application framework
 */
class Runtime
{
public:
    Thread makeThread(const Thread::ThreadConfig& config, auto& function);
};

} // namespace foundation
