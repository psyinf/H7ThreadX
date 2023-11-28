cmake_minimum_required(VERSION 3.20)

project("H7ThreadX" C CXX ASM)

include(cmake/st-project.cmake)
add_subdirectory(Config)
add_subdirectory(foundation)
add_subdirectory(Middlewares)
add_subdirectory(Drivers)

add_executable(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} PRIVATE foundation threadx hal CMSIS Config)
add_st_target_properties(${PROJECT_NAME})