#pragma once
#include <array>
#include <cstdint>
#include <string>

namespace foundation {





class Runtime {

public:
    void createThreads();
    static constexpr int THREAD_STACK_SIZE = 1024;
    std::array<uint8_t, THREAD_STACK_SIZE> thread_stack;
    std::array<uint8_t, THREAD_STACK_SIZE> thread_stack2;
    
};

}

