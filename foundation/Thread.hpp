#pragma once
#include "FixedString/FixedString.hpp"
#include <tx_api.h>

#include <array>

namespace foundation {

class Thread
{
    using ThreadStack = std::array<char, 1024>;

public:
    using ThreadName = fss::fixed_size_str<63>;
    using ThreadFunction = std::function<void(void)>;

    struct ThreadConfig
    {
        // https://learn.microsoft.com/en-us/azure/rtos/threadx/chapter4#parameters-54
        std::uint32_t priority{15};
        std::uint32_t preempt_threshold{15};
        std::uint32_t time_slice;
        bool          auto_start{true};
    };

    Thread(const ThreadName& name, const ThreadConfig cfg, auto& lambda)
      : name(name)
    {
        auto ret = tx_thread_create(&threadControlBlock,
                                    const_cast<char*>(name.c_str()),
                                    lambda,
                                    0,
                                    stack.data(),
                                    stack.size(),
                                    cfg.priority,
                                    cfg.preempt_threshold,
                                    TX_NO_TIME_SLICE, // for now, todo: config
                                    cfg.auto_start ? TX_AUTO_START : TX_DONT_START);
    };

    Thread(const Thread& rhs) = delete;

    Thread(Thread&&) = default;

    ~Thread() { tx_thread_delete(&threadControlBlock); }

    void start() {}

private:
    TX_THREAD   threadControlBlock{};
    ThreadName  name;
    ThreadStack stack;
};

} // namespace foundation