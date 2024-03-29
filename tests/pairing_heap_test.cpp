// tests/heap_test.cpp
#include <gtest/gtest.h>
#include "pairing_heap.hpp"
#include <algorithm>
#include <stdexcept>
#include <vector>

using namespace std;

TEST(PairingHeapTest, InsertAndExtractMin) {
    PairingHeap heap;
    heap.insert(3);
    heap.insert(1);
    heap.insert(2);

    EXPECT_EQ(heap.getMinimum(), 1);  
    heap.deleteMinimum();
    EXPECT_EQ(heap.getMinimum(), 2);
}

TEST(PairingHeapTest, HandleEmptyHeap) {
    PairingHeap heap;
    EXPECT_THROW(heap.getMinimum(), exception);
    EXPECT_THROW(heap.deleteMinimum(), exception);
}

TEST(PairingHeapTest, InsertAndDeleteMultiple) {
    PairingHeap heap;
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

TEST(PairingHeapTest, HandleLargeNumberOfElements) {
    PairingHeap heap;
    for (int i = 1000; i >= 1; i--) {
        heap.insert(i);
    }

    for (int i = 1; i <= 1000; i++) {
        EXPECT_EQ(heap.getMinimum(), i);
        heap.deleteMinimum();
    }
}

TEST(PairingHeapTest, ComplexOperations) {
    PairingHeap heap;
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

TEST(PairingHeapTest, RepeatedInsertAndDelete) {
    PairingHeap heap;
    for (int i = 0; i < 10; i++) {
        heap.insert(i);
        heap.deleteMinimum();
    }

    EXPECT_THROW(heap.getMinimum(), exception);
}

TEST(PairingHeapTest, InsertDuplicateValues) {
    PairingHeap heap;
    for (int i = 0; i < 5; i++) {
        heap.insert(5);
    }

    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(heap.getMinimum(), 5);
        heap.deleteMinimum();
    }

    EXPECT_THROW(heap.getMinimum(), exception);
}

TEST(PairingHeapTest, InsertInDescendingOrder) {
    PairingHeap heap;
    for (int i = 10; i > 0; i--) {
        heap.insert(i);
    }

    for (int i = 1; i <= 10; i++) {
        EXPECT_EQ(heap.getMinimum(), i);
        heap.deleteMinimum();
    }
}

TEST(PairingHeapTest, RandomInsertAndDelete) {
    PairingHeap heap;
    vector<int> numbers = {7, 3, 9, 1, 4, 8, 2, 5, 6, 0};

    for (int num : numbers) {
        heap.insert(num);
    }

    sort(numbers.begin(), numbers.end());
    for (int expected : numbers) {
        EXPECT_EQ(heap.getMinimum(), expected);
        heap.deleteMinimum();
    }
}

TEST(PairingHeapTest, RandomTest) {
    PairingHeap heap;
    for (int i = 0; i < 10000; i++) {
        heap.insert(rand() % 10000);
    }

    int last = -1;
    while (true) {
        try {
            int current = heap.getMinimum();
            heap.deleteMinimum();
            EXPECT_GE(current, last);
            last = current;
        } catch (exception&) {
            break;
        }
    }
}

TEST(PairingHeapTest, InsertNegativeNumbers) {
    PairingHeap heap;
    heap.insert(-1);
    heap.insert(-3);
    heap.insert(-2);

    EXPECT_EQ(heap.getMinimum(), -3);
    heap.deleteMinimum();

    EXPECT_EQ(heap.getMinimum(), -2);
    heap.deleteMinimum();

    EXPECT_EQ(heap.getMinimum(), -1);
    heap.deleteMinimum();

    EXPECT_THROW(heap.getMinimum(), exception);
}
