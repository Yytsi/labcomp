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
target_link_libraries(runUnitTests ${GTEST_LIBRARIES} pthread)

# Lisää kattavuusliput, jos testejä varten rakennetaan
if(CMAKE_BUILD_TYPE STREQUAL "Coverage")
    set_target_properties(runUnitTests PROPERTIES
        COMPILE_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage"
        LINK_FLAGS "-fprofile-arcs -ftest-coverage"
    )
endif()

add_test(NAME HeapTest COMMAND runUnitTests)
