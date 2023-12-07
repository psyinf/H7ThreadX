#include "HAL.hpp"
#include <stm32h7xx_hal.h>

void foundation::HAL::systemReset()
{
    //TODO: log  
    HAL_NVIC_SystemReset();
}
