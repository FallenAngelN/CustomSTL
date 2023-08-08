cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(example_pair
    VERSION 1.0.0.0
    DESCRIPTION "Example of functionally ${PROJECT_NAME}. By Fallen Angel"
    LANGUAGES CXX)

file(GLOB SRC_${PROJECT_NAME} "${PROJECT_NAME}.cpp")

add_executable(${PROJECT_NAME} SRC_${EXAMPLE_VECTOR})
