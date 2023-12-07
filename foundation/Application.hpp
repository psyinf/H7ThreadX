#pragma once

#include "Runtime.hpp"

#include <span>

class Application
{
    using memory_view = std::span<UCHAR>;

public:
    Application(memory_view&& appMemoryPool)
      : applicationMemory(appMemoryPool)
    {
    }

    foundation::Runtime& getRuntime() { return runtime; }

private:
    foundation::Runtime runtime;
    memory_view         applicationMemory;
};