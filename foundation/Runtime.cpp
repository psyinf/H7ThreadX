#include "Runtime.hpp"
#include "HAL.hpp"
#include "FixedString/FixedString.hpp"
#include <cstdint>
#include <functional>
#include <tx_api.h>


void foundation::Runtime::makeThread(foundation::Thread::ThreadName&&        name,
                                     const foundation::Thread::ThreadConfig& config,
                                     const Func&                             func)
{
    auto function = func.target<void (*)(ULONG entry_input)>();
    if (function == nullptr)
    {
        HAL::systemReset();
        //TODO: forward of member function 
        /*
        auto f = [&](auto f) { func(0); };
        threads.emplace(
            std::piecewise_construct, std::forward_as_tuple(name), std::forward_as_tuple(name, config, f));
*/
        return;
    }
    else
    {
        threads.emplace(
            std::piecewise_construct, std::forward_as_tuple(name), std::forward_as_tuple(name, config, *function));
    }
}