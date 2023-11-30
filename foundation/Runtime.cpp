#include "Runtime.hpp"
#include "FixedString/FixedString.hpp"
#include <cstdint>
#include <main.h>
#include <tx_api.h>

class Thread
{
    using ThreadName = fss::fixed_size_str<63>;
    using ThreadStack = std::array<char, 1024>;

    struct ThreadConfig
    {
        // https://learn.microsoft.com/en-us/azure/rtos/threadx/chapter4#parameters-54
        std::uint32_t priority{15};
        std::uint32_t preempt_threshold{15};
        std::uint32_t time_slice;
        bool          auto_start{false};
    };

public:
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

    ~Thread() { tx_thread_delete(&threadControlBlock); }

    void start() {}

private:
    TX_THREAD   threadControlBlock{};
    ThreadName  name;
    ThreadStack stack;
};

template<typename...ValidValues>
static void ErrorHandler(UINT result)
{

}

class Mutex
{
public:
    Mutex() { tx_mutex_create(&mutex, nullptr, TX_NO_INHERIT); }

    ~Mutex() { tx_mutex_delete(&mutex); }

    void lock() { tx_mutex_get(&mutex, TX_WAIT_FOREVER); }

    bool try_lock()
    {
        // TODO: handle TX_MUTEX_ERROR and TX_WAIT_ERROR
        auto ret = tx_mutex_get(&mutex, TX_NO_WAIT);
        switch (ret)
        {
        case TX_SUCCESS:
            return true;
        case TX_NOT_AVAILABLE:
            return false;
        default:
            break;
        }
    }

    void release() { tx_mutex_put(&mutex); }

private:
    TX_MUTEX mutex;
};

void foundation::Runtime::createThreads()
{
    static Mutex       ledLockPin;
    static auto my_thread_entry = +[](long unsigned int initial) {
        auto i = 5;
        while (i--)
        {
            /* USER CODE END WHILE */
            ledLockPin.lock();
            HAL_GPIO_TogglePin(LED1_RGB_GPIO_Port, LED1_RGB_Pin);
            tx_thread_sleep(110);
            ledLockPin.release();
            /* USER CODE BEGIN 3 */
        }
    };
    static auto my_thread_entry2 = +[](long unsigned int initial) {
        while (1)
        {
            /* USER CODE END WHILE */
            ledLockPin.lock();
            HAL_GPIO_TogglePin(LED3_RGB_GPIO_Port, LED3_RGB_Pin);
            tx_thread_sleep(210);
            ledLockPin.release();
            /* USER CODE BEGIN 3 */
        }
    };
    static Thread thread = Thread{{"1"}, {}, my_thread_entry};
    static Thread thread2 = Thread{{"1"}, {}, my_thread_entry2};
}