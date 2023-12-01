#include "Runtime.hpp"
#include "FixedString/FixedString.hpp"
#include <cstdint>
#include <main.h>
#include <tx_api.h>


foundation::Thread foundation::Runtime::makeThread(const foundation::Thread::ThreadConfig& config, auto& threadFunction )
{

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
    static Thread thread = Thread{{"1"}, {}, my_thread_entry};
    static Thread thread2 = Thread{{"1"}, {}, my_thread_entry2};
    */
}