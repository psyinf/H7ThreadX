project(CMSIS)

add_library(${PROJECT_NAME} INTERFACE)

target_link_directories(${PROJECT_NAME} INTERFACE
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Drivers\\CMSIS\\Device\\ST\\STM32H7xx\\Include>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Drivers\\CMSIS\\Include>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:${PROJECT_SOURCE_DIR}/Drivers\\CMSIS\\Device\\ST\\STM32H7xx\\Include>"
    "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:${PROJECT_SOURCE_DIR}/Drivers\\CMSIS\\Include>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Drivers\\CMSIS\\Device\\ST\\STM32H7xx\\Include>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:${PROJECT_SOURCE_DIR}/Drivers\\CMSIS\\Include>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:CXX>>:${PROJECT_SOURCE_DIR}/Drivers\\CMSIS\\Device\\ST\\STM32H7xx\\Include>"
    "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:CXX>>:${PROJECT_SOURCE_DIR}/Drivers\\CMSIS\\Include>"
)
