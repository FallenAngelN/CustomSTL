cmake_minimum_required(VERSION 3.14)

project(custom_double_list
    VERSION 1.0.0.0
    DESCRIPTION "Аналог std::list из STL"
    LANGUAGES CXX)

file(GLOB SOURCES ../../src/${PROJECT_NAME}/*.cpp)

include_directories(.)

if(STL_SHARED_LIBS)
    add_library(${PROJECT_NAME} SHARED ${SOURCES})
else()
    add_library(${PROJECT_NAME} STATIC ${SOURCES})
endif()

if(STL_INSTALL_LIBS)
    install(TARGETS ${PROJECT_NAME} DESTINATION lib/${CMAKE_PROJECT_NAME})
    file(GLOB HEADERS *.hpp)
    file(GLOB TEMPLATE template/*.tpp)
    install(FILES ${HEADERS} DESTINATION include/${CMAKE_PROJECT_NAME})
    install(FILES ${TEMPLATE} DESTINATION include/${CMAKE_PROJECT_NAME}/template)
endif()









