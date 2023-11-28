#include "Runtime.hpp"
#include <tx_api.h>
//#include <main.h>
foundation::Runtime::Runtime() {

    auto my_thread_entry = +[](long unsigned int initial) {
        while (1)
        {
            /* USER CODE END WHILE */
            HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_10);
            tx_thread_sleep(20);
            /* USER CODE BEGIN 3 */
        }
    };
    TX_THREAD thread_ptr;

    const std::string s("my");
    tx_thread_create(&thread_ptr, const_cast<char*>(s.c_str()), my_thread_entry, 0x1234, thread_stack.data(), THREAD_STACK_SIZE, 15, 15, 1, TX_AUTO_START);

}