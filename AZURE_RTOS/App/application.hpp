#pragma once

#include "foundation/Runtime.hpp"

#include <span>

class Application
{
    using memory_view = std::span<UCHAR>;

public:
    Application(memory_view&& appMemoryPool)
      : appMemory(appMemoryPool)
    {
    }

    foundation::Runtime& getRuntime() { return runtime; }

private:
    foundation::Runtime runtime;
    memory_view         appMemory;
};