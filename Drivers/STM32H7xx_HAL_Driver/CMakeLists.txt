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
    "${PROJECT_SOURCE_DIR}/Inc"
    "${PROJECT_SOURCE_DIR}/Legacy"
)

target_compile_options(
    ${PROJECT_NAME} INTERFACE
    "-mcpu=cortex-m7"
    "-mfpu=fpv5-d16"
    "-mfloat-abi=hard"
)


target_compile_definitions(
    ${PROJECT_NAME} PRIVATE
    "$<$<CONFIG:Debug>:DEBUG>"
    "STM32H743xx"
)
target_link_libraries(${PROJECT_NAME} PRIVATE
    Config CMSIS
)