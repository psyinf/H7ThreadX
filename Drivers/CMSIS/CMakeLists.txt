project(CMSIS)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE
    "${PROJECT_SOURCE_DIR}/Device/ST/STM32H7xx/Include"
    "${PROJECT_SOURCE_DIR}/Include"
)
target_compile_options(
    ${PROJECT_NAME} INTERFACE
    "-mcpu=cortex-m7"
    "-mfpu=fpv5-d16"
    "-mfloat-abi=hard"
)
target_link_libraries(${PROJECT_NAME} INTERFACE Config)