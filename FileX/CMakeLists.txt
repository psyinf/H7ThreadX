project(filex_driver)

add_library(${PROJECT_NAME} STATIC)

target_include_directories(${PROJECT_NAME} PUBLIC
    "${PROJECT_SOURCE_DIR}/Target"
    "${PROJECT_SOURCE_DIR}/App"
)

target_sources(${PROJECT_NAME} PUBLIC
    "Target/fx_stm32_sd_driver_glue.c"
    "App/app_filex.c"
)

target_compile_definitions(
    ${PROJECT_NAME} PRIVATE
    "$<$<CONFIG:Debug>:DEBUG>"
    "STM32H743xx"
)
target_compile_options(
    ${PROJECT_NAME} PUBLIC
    "-mcpu=cortex-m7"
    "-mfpu=fpv5-d16"
    "-mfloat-abi=hard"
)


target_link_libraries(${PROJECT_NAME}
PRIVATE
    filex threadx hal CMSIS Config
)