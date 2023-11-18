cmake_minimum_required(VERSION 3.10)
project(HeapComparisonProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(Main src/main.cpp src/binary_heap.cpp)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runUnitTests tests/test_main.cpp tests/binary_heap_test.cpp src/binary_heap.cpp)
add_executable(benchmark src/heap_benchmarking.cpp)
target_link_libraries(runUnitTests ${GTEST_LIBRARIES} pthread)

# Lisää kattavuusliput, jos testejä varten rakennetaan
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

add_test(NAME HeapTest COMMAND runUnitTests)
