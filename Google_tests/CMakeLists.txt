project(Google_tests)
add_subdirectory(lib)
add_executable(Google_Tests_run QueueTest.cpp)

include_directories(${CMAKE_SOURCE_DIR}/../Containers_lib/Collections)
include_directories(Containers_lib/Container_of_containers)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

target_link_libraries(Google_Tests_run Containers_lib)

target_link_libraries(Google_Tests_run gtest gtest_main)





