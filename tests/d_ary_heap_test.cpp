#include <gtest/gtest.h>
#include "d_ary_heap.hpp"
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <cstdlib>

using namespace std;

class DaryHeapTest : public ::testing::TestWithParam<int> {
protected:
    DaryHeap heap;
    DaryHeapTest() : heap(GetParam()) {}
};

INSTANTIATE_TEST_SUITE_P(
    DifferentDValues,
    DaryHeapTest,
    ::testing::Values(2, 3, 4, 5, 6, 10)
);

TEST_P(DaryHeapTest, InsertAndExtractMin) {
    heap.insert(3);
    heap.insert(1);
    heap.insert(2);

    EXPECT_EQ(heap.getMinimum(), 1);
    heap.deleteMinimum();
    EXPECT_EQ(heap.getMinimum(), 2);
}

TEST_P(DaryHeapTest, HandleEmptyHeap) {
    EXPECT_THROW(heap.getMinimum(), std::exception);
    EXPECT_THROW(heap.deleteMinimum(), std::exception);
}

TEST_P(DaryHeapTest, InsertAndDeleteMultiple) {
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
    heap.deleteMinimum();

    EXPECT_THROW(heap.getMinimum(), std::exception);
}

TEST_P(DaryHeapTest, HandleLargeNumberOfElements) {
    for (int i = 1000; i >= 1; --i) {
        heap.insert(i);
    }

    for (int i = 1; i <= 1000; ++i) {
        EXPECT_EQ(heap.getMinimum(), i);
        heap.deleteMinimum();
    }
}

TEST_P(DaryHeapTest, ComplexOperations) {
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

TEST_P(DaryHeapTest, RepeatedInsertAndDelete) {
    for (int i = 0; i < 10; ++i) {
        heap.insert(i);
        heap.deleteMinimum();
    }

    EXPECT_THROW(heap.getMinimum(), std::exception);
}

TEST_P(DaryHeapTest, InsertDuplicateValues) {
    for (int i = 0; i < 5; ++i) {
        heap.insert(5);
    }

    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(heap.getMinimum(), 5);
        heap.deleteMinimum();
    }

    EXPECT_THROW(heap.getMinimum(), std::exception);
}

TEST_P(DaryHeapTest, InsertInDescendingOrder) {
    for (int i = 10; i > 0; --i) {
        heap.insert(i);
    }

    for (int i = 1; i <= 10; ++i) {
        EXPECT_EQ(heap.getMinimum(), i);
        heap.deleteMinimum();
    }
}

TEST_P(DaryHeapTest, RandomInsertAndDelete) {
    std::vector<int> numbers = {7, 3, 9, 1, 4, 8, 2, 5, 6, 0};

    for (int num : numbers) {
        heap.insert(num);
    }

    std::sort(numbers.begin(), numbers.end());
    for (int expected : numbers) {
        EXPECT_EQ(heap.getMinimum(), expected);
        heap.deleteMinimum();
    }
}

TEST_P(DaryHeapTest, RandomTest) {
    for (int i = 0; i < 10000; ++i) {
        heap.insert(std::rand() % 10000);
    }

    int last = -1;
    while (true) {
        try {
            int current = heap.getMinimum();
            heap.deleteMinimum();
            EXPECT_GE(current, last);
            last = current;
        } catch (std::exception&) {
            break;
        }
    }
}

TEST_P(DaryHeapTest, InsertNegativeNumbers) {
    heap.insert(-1);
    heap.insert(-3);
    heap.insert(-2);

    EXPECT_EQ(heap.getMinimum(), -3);
    heap.deleteMinimum();

    EXPECT_EQ(heap.getMinimum(), -2);
    heap.deleteMinimum();

    EXPECT_EQ(heap.getMinimum(), -1);
    heap.deleteMinimum();

    EXPECT_THROW(heap.getMinimum(), std::exception);
}