cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
project("H7ThreadX" C CXX ASM)

add_subdirectory(Config)
add_subdirectory(foundation)
add_subdirectory(Middlewares)
add_subdirectory(Drivers)
add_subdirectory(Core)
add_subdirectory(FileX)
add_subdirectory(AZURE_RTOS)
add_subdirectory(apps)


#TODO: this breaks the build
find_program(GRAPHVIZ dot)
if(GRAPHVIZ AND FIXED) 
    add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/_graphviz
        COMMAND ${CMAKE_COMMAND} "--graphviz=graphviz/deps.txt" .
        COMMAND dot -Tsvg graphviz/deps.txt -o deps.svg
        COMMAND dot -Tpng graphviz/deps.txt -o deps.png
        COMMENT "Plotting dependencies graph to deps.svg"
        #DEPENDS App
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}")
    add_custom_target(graphviz ALL
        DEPENDS ${CMAKE_BINARY_DIR}/_graphviz)
    set_target_properties(graphviz PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)
endif()

