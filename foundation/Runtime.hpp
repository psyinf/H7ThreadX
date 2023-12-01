#pragma once
#include "Thread.hpp"
#include <array>
#include <cstdint>
#include <functional>
#include <unordered_map>
namespace foundation {

/**
 * @brief Runtime/Application framework
 */
class Runtime
{
    std::unordered_map<Thread::ThreadName, Thread> threads;

public:
    using Func = std::function<void(ULONG)>;
    void makeThread(Thread::ThreadName&& name, const Thread::ThreadConfig& config, const Func& function);
};

} // namespace foundation
