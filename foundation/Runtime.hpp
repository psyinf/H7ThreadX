#pragma once
#include <array>
#include <cstdint>
#include <string>

namespace foundation {





class Runtime {

    Runtime();
    static constexpr int THREAD_STACK_SIZE = 1024;
    std::array<uint8_t, THREAD_STACK_SIZE> thread_stack;
    
};

}

