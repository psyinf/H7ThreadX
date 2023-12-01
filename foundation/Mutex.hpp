#pragma once

/**
 * @brief RAII wrapper for ThreadX mutex. 
 * @todo proper error handling
 * @todo Unit testing
*/
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