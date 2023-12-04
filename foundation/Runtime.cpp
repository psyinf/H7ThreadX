#include "Runtime.hpp"
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
    /*
    static Mutex       ledLockPin;
    static auto my_thread_entry = +[](long unsigned int initial) {
        auto i = 5;
        while (i--)
        {

            ledLockPin.lock();
            HAL_GPIO_TogglePin(LED1_RGB_GPIO_Port, LED1_RGB_Pin);
            tx_thread_sleep(110);
            ledLockPin.release();

        }
    };
    static auto my_thread_entry2 = +[](long unsigned int initial) {
        while (1)
        {

            ledLockPin.lock();
            HAL_GPIO_TogglePin(LED3_RGB_GPIO_Port, LED3_RGB_Pin);
            tx_thread_sleep(210);
            ledLockPin.release();

        }
    };
    static Thread thread =
    static Thread thread2 = Thread{{"1"}, {}, my_thread_entry2};
    */
}