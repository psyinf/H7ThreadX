project(Core)


add_library(${PROJECT_NAME} STATIC)


target_compile_definitions(
    ${PROJECT_NAME} PRIVATE
    "$<$<CONFIG:Debug>:DEBUG>"
    "STM32H743xx"
)

target_sources(${PROJECT_NAME}
PUBLIC
    "Src/adc.c"
    "Src/app_threadx.c"
    "Src/dfsdm.c"
    "Src/eth.c"
    "Src/fmc.c"
    "Src/gpio.c"
    "Src/i2c.c"
    "Src/ltdc.c"
    "Src/main.c"
    "Src/quadspi.c"
    "Src/sai.c"
    "Src/sdmmc.c"
    "Src/stm32h7xx_hal_msp.c"
    "Src/stm32h7xx_hal_timebase_tim.c"
    "Src/stm32h7xx_it.c"
    "Src/syscalls.c"
    "Src/sysmem.c"
    "Src/system_stm32h7xx.c"
    "Src/tx_initialize_low_level.S"
    "Src/usart.c"
    "Src/usb_otg.c"
    "Startup/startup_stm32h743xihx.s"
)
target_include_directories(
    ${PROJECT_NAME} PUBLIC
    "${PROJECT_SOURCE_DIR}/Inc"
 )
target_link_libraries(
    ${PROJECT_NAME} PUBLIC
    hal threadx
)
