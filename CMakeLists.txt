cmake_minimum_required(VERSION 3.20)

project("H7ThreadX" C CXX ASM)

include(cmake/st-project.cmake)

add_subdirectory(foundation)
add_subdirectory(Middlewares)

add_executable(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} foundation threadx)
add_st_target_properties(${PROJECT_NAME})