#include "Runtime.hpp"
#include <tx_api.h>
#include <main.h>

void foundation::Runtime::createThreads() {
    static auto my_thread_entry = +[](long unsigned int initial) {
        while (1)
        {
            /* USER CODE END WHILE */
            HAL_GPIO_TogglePin(LED1_RGB_GPIO_Port, LED1_RGB_Pin);
            tx_thread_sleep(10);

            /* USER CODE BEGIN 3 */
        }
        };
    static auto my_thread2_entry = +[](long unsigned int initial) {
        while (1)
        {
            /* USER CODE END WHILE */
            HAL_GPIO_TogglePin(LED3_RGB_GPIO_Port, LED3_RGB_Pin);
            tx_thread_sleep(5);

            /* USER CODE BEGIN 3 */
        }
        };
    
    TX_THREAD thread_ptr;
    TX_THREAD thread2_ptr;


    const std::string s("my");
    const std::string s2("my");
    tx_thread_create(&thread_ptr, const_cast<char*>(s.c_str()), my_thread_entry, 0x1234, thread_stack.data(), THREAD_STACK_SIZE, 15, 15, 1, TX_AUTO_START);
    tx_thread_create(&thread2_ptr, const_cast<char*>(s2.c_str()), my_thread2_entry, 0x1234, thread_stack2.data(), THREAD_STACK_SIZE, 15, 15, 2, TX_AUTO_START);

}