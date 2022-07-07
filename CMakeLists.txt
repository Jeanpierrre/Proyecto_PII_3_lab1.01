cmake_minimum_required(VERSION 3.21.1)
project(Allego)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
        Source/main.cpp
        )

set (HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Headers/)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

add_executable(Allego ${SOURCES})
target_include_directories(Allego PRIVATE ${HEADERS_DIR} ${SFML_INCLUDE_DIRS})
target_link_libraries(Allego sfml-graphics sfml-system sfml-audio ${SFML_DEPENDENCIES})