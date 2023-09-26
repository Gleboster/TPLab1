cmake_minimum_required(VERSION 3.26)
project(Lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab1 main.cpp
        Collections/Collection.cpp
        Collections/Collection.h
        Collections/Stack.cpp
        Collections/Stack.h
        Collections/Deque.cpp
        Collections/Deque.h
        Collections/List.cpp
        Collections/List.h
        "Container of Containers/Queue.h"
)
