cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(example_vector
    VERSION 1.0.0.0
    DESCRIPTION "Example of functionally ${PROJECT_NAME}. By Fallen Angel"
    LANGUAGES CXX)

file(GLOB SRC_${PROJECT_NAME} "${PROJECT_NAME}.cpp")

add_custom_target(examples COMMENT "Build examples")
add_custom_command(
    TARGET "examples"
    POST_BUILD
    COMMENT "Build example custom_stl::Vector"
    COMMAND g++ ${SRC_${PROJECT_NAME}} -o ${PROJECT_NAME})
