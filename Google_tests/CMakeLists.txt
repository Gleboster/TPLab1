project(Google_tests)
add_subdirectory(lib)
add_executable(Google_Tests_run QueueTest.cpp StackTest.cpp ListTest.cpp
        ListPerformance.cpp
        DequeTest.cpp
        SerializeTest.cpp
        DeserializeTest.cpp
        De_and_Serialization.cpp)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

target_link_libraries(Google_Tests_run Containers_lib)

target_link_libraries(Google_Tests_run gtest gtest_main)





