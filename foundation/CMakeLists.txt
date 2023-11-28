project (foundation)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} 
    PUBLIC
        Runtime.hpp
        Runtime.cpp
)

target_link_libraries(${PROJECT_NAME}
PRIVATE
    threadx
)

target_include_directories(
  ${PROJECT_NAME}
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
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
    "$<$<CONFIG:Debug>:${PROJECT_SOURCE_DIR}/STM32H743XIHX_FLASH.ld>"
    "$<$<NOT:$<CONFIG:Debug>>:${PROJECT_SOURCE_DIR}/STM32H743XIHX_FLASH.ld>"
)
