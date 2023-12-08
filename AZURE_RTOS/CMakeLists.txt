project(App)

add_executable(${PROJECT_NAME})

target_compile_definitions(
    ${PROJECT_NAME} PRIVATE
    "$<$<CONFIG:Debug>:DEBUG>"
    "STM32H743xx"
)
target_link_options(
    ${PROJECT_NAME} PRIVATE
    "-mcpu=cortex-m7"
    "-mfpu=fpv5-d16"
    "-mfloat-abi=hard"
    -T "${CMAKE_HOME_DIRECTORY}/STM32H743XIHX_FLASH.ld"
)

target_link_libraries(${PROJECT_NAME} PRIVATE foundation Core filex_driver filex)

set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/App/app_azure_rtos.c PROPERTIES LANGUAGE CXX)

target_sources(
    ${PROJECT_NAME} PRIVATE
    "App/app_azure_rtos.c"
)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${PROJECT_NAME}>
)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex
    $<TARGET_FILE:${PROJECT_NAME}> ${PROJECT_NAME}.hex
)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary
    $<TARGET_FILE:${PROJECT_NAME}> ${PROJECT_NAME}.bin
)

