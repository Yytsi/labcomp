// tests/heap_test.cpp
#include <gtest/gtest.h>
#include "binary_heap.hpp"

TEST(BinaryHeapTest, InsertAndExtractMin) {
    BinaryHeap heap;
    heap.insert(3);
    heap.insert(1);
    heap.insert(2);

    EXPECT_EQ(heap.getMinimum(), 1);
    heap.deleteMinimum();
    EXPECT_EQ(heap.getMinimum(), 2);
}

TEST(BinaryHeapTest, HandleEmptyHeap) {
    BinaryHeap heap;
    EXPECT_THROW(heap.getMinimum(), std::exception);
    EXPECT_THROW(heap.deleteMinimum(), std::exception);
}

TEST(BinaryHeapTest, InsertAndDeleteMultiple) {
    BinaryHeap heap;
    heap.insert(5);
    heap.insert(3);
    heap.insert(8);
    heap.insert(1);
    heap.insert(4);

    EXPECT_EQ(heap.getMinimum(), 1);
    heap.deleteMinimum();

    EXPECT_EQ(heap.getMinimum(), 3);
    heap.deleteMinimum();

    EXPECT_EQ(heap.getMinimum(), 4);
    heap.deleteMinimum();

    EXPECT_EQ(heap.getMinimum(), 5);
    heap.deleteMinimum();

    EXPECT_EQ(heap.getMinimum(), 8);
}

TEST(BinaryHeapTest, HandleLargeNumberOfElements) {
    BinaryHeap heap;
    for (int i = 1000; i >= 1; i--) {
        heap.insert(i);
    }

    for (int i = 1; i <= 1000; i++) {
        EXPECT_EQ(heap.getMinimum(), i);
        heap.deleteMinimum();
    }
}

TEST(BinaryHeapTest, ComplexOperations) {
    BinaryHeap heap;
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(6);
    heap.insert(1);
    heap.deleteMinimum();
    heap.insert(2);
    heap.deleteMinimum();

    EXPECT_EQ(heap.getMinimum(), 5);
}
