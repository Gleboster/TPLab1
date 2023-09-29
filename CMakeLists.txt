cmake_minimum_required(VERSION 3.26)
project(Lab1)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)
add_executable(Lab1 ${SOURCE_FILES})

include_directories(Containers_lib)
add_subdirectory(Containers_lib)

target_link_libraries(Lab1 Containers_lib)

add_subdirectory(Google_tests)

