project(hal)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} PUBLIC
	"Src/stm32h7xx_hal_adc_ex.c"
    "Src/stm32h7xx_hal_adc.c"
    "Src/stm32h7xx_hal_cortex.c"
    "Src/stm32h7xx_hal_dfsdm.c"
    "Src/stm32h7xx_hal_dma_ex.c"
    "Src/stm32h7xx_hal_dma.c"
    "Src/stm32h7xx_hal_eth_ex.c"
    "Src/stm32h7xx_hal_eth.c"
    "Src/stm32h7xx_hal_exti.c"
    "Src/stm32h7xx_hal_flash_ex.c"
    "Src/stm32h7xx_hal_flash.c"
    "Src/stm32h7xx_hal_gpio.c"
    "Src/stm32h7xx_hal_hsem.c"
    "Src/stm32h7xx_hal_i2c_ex.c"
    "Src/stm32h7xx_hal_i2c.c"
    "Src/stm32h7xx_hal_ltdc_ex.c"
    "Src/stm32h7xx_hal_ltdc.c"
    "Src/stm32h7xx_hal_mdma.c"
    "Src/stm32h7xx_hal_nor.c"
    "Src/stm32h7xx_hal_pcd_ex.c"
    "Src/stm32h7xx_hal_pcd.c"
    "Src/stm32h7xx_hal_pwr_ex.c"
    "Src/stm32h7xx_hal_pwr.c"
    "Src/stm32h7xx_hal_qspi.c"
    "Src/stm32h7xx_hal_rcc_ex.c"
    "Src/stm32h7xx_hal_rcc.c"
    "Src/stm32h7xx_hal_sai_ex.c"
    "Src/stm32h7xx_hal_sai.c"
    "Src/stm32h7xx_hal_sd_ex.c"
    "Src/stm32h7xx_hal_sd.c"
    "Src/stm32h7xx_hal_sdram.c"
    "Src/stm32h7xx_hal_sram.c"
    "Src/stm32h7xx_hal_tim_ex.c"
    "Src/stm32h7xx_hal_tim.c"
    "Src/stm32h7xx_hal_uart_ex.c"
    "Src/stm32h7xx_hal_uart.c"
    "Src/stm32h7xx_hal.c"
    "Src/stm32h7xx_ll_delayblock.c"
    "Src/stm32h7xx_ll_fmc.c"
    "Src/stm32h7xx_ll_sdmmc.c"
    "Src/stm32h7xx_ll_usb.c"
)
target_include_directories(${PROJECT_NAME} PUBLIC
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Inc>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Legacy>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:${PROJECT_SOURCE_DIR}/Inc>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:${PROJECT_SOURCE_DIR}/Legacy>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Inc>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Legacy>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:CXX>>:${PROJECT_SOURCE_DIR}/Inc>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:CXX>>:${PROJECT_SOURCE_DIR}/Legacy>"
)

target_compile_options(
    ${PROJECT_NAME} PRIVATE
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:ASM>>:-g3>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:-g3>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:-g3>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:ASM>>:-g0>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:-g0>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:CXX>>:-g0>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:-Os>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:CXX>>:-Os>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:CXX>>:>"
    "$<$<CONFIG:Debug>:-mcpu=cortex-m7>"
    "$<$<CONFIG:Debug>:-mfpu=fpv5-d16>"
    "$<$<CONFIG:Debug>:-mfloat-abi=hard>"
    "$<$<NOT:$<CONFIG:Debug>>:-mcpu=cortex-m7>"
    "$<$<NOT:$<CONFIG:Debug>>:-mfpu=fpv5-d16>"
    "$<$<NOT:$<CONFIG:Debug>>:-mfloat-abi=hard>"
)

target_link_options(
    ${PROJECT_NAME} PRIVATE
    "$<$<CONFIG:Debug>:-mcpu=cortex-m7>"
    "$<$<CONFIG:Debug>:-mfpu=fpv5-d16>"
    "$<$<CONFIG:Debug>:-mfloat-abi=hard>"
    "$<$<NOT:$<CONFIG:Debug>>:-mcpu=cortex-m7>"
    "$<$<NOT:$<CONFIG:Debug>>:-mfpu=fpv5-d16>"
    "$<$<NOT:$<CONFIG:Debug>>:-mfloat-abi=hard>"
    -T
    #"$<$<CONFIG:Debug>:${PROJECT_SOURCE_DIR}/STM32H743XIHX_FLASH.ld>"
    #"$<$<NOT:$<CONFIG:Debug>>:${PROJECT_SOURCE_DIR}/STM32H743XIHX_FLASH.ld>"
)
target_compile_definitions(
    ${PROJECT_NAME} PRIVATE
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:ASM>>:DEBUG>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:DEBUG>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:TX_INCLUDE_USER_DEFINE_FILE>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:USE_HAL_DRIVER>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:STM32H743xx>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:DEBUG>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:TX_INCLUDE_USER_DEFINE_FILE>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:USE_HAL_DRIVER>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:STM32H743xx>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:TX_INCLUDE_USER_DEFINE_FILE>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:USE_HAL_DRIVER>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:STM32H743xx>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:CXX>>:TX_INCLUDE_USER_DEFINE_FILE>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:CXX>>:USE_HAL_DRIVER>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:CXX>>:STM32H743xx>"
)
target_link_libraries(${PROJECT_NAME} PRIVATE
    Config CMSIS
)