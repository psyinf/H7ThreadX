project (foundation)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} 
    PUBLIC
        Runtime.cpp
        HAL.cpp
)

target_link_libraries(${PROJECT_NAME}
PRIVATE
    threadx CMSIS hal Config
)

target_include_directories(
  ${PROJECT_NAME}
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)


target_compile_options(
    ${PROJECT_NAME} PRIVATE
)


target_compile_definitions(
    ${PROJECT_NAME} PRIVATE
    "$<$<CONFIG:Debug>:DEBUG>"
    "STM32H743xx"
)