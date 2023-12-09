#include "../include/binary_heap.hpp"
#include <stdexcept>

// Inserts a new value into the heap
void BinaryHeap::insert(int value) {
    heap.push_back(value); // Add the new value at the end of the heap
    heapifyUp(heap.size() - 1); // Maintain heap order after insertion
}

// Returns the minimum value in the heap
int BinaryHeap::getMinimum() const {
    if (heap.empty()) throw std::runtime_error("Tyhjästä binäärikeosta minimi.");
    return heap[0];
}

void BinaryHeap::deleteMinimum() {
    if (heap.empty()) throw std::runtime_error("Tyhjästä binäärikeosta poisto.");
    heap[0] = heap.back(); // Replace the root with the last element in the heap
    heap.pop_back(); // Remove the last element
    if (!heap.empty()) heapifyDown(0); // Maintain heap order after deletion
}

void BinaryHeap::heapifyDown(int index) {
    int smallest = index;
    int leftChild = 2 * index + 1; // Calculate index of left child
    int rightChild = 2 * index + 2; // Calculate index of right child

    // Check if the left child exists and is smaller than the current node
    if (leftChild < static_cast<int>(heap.size()) && heap[leftChild] < heap[smallest]) {
        smallest = leftChild;
    }
    // Check if the right child exists and is smaller than the current node
    if (rightChild < static_cast<int>(heap.size()) && heap[rightChild] < heap[smallest]) {
        smallest = rightChild;
    }

    if (smallest != index) {
        std::swap(heap[index], heap[smallest]);
        heapifyDown(smallest);
    }
}

void BinaryHeap::heapifyUp(int index) {
    // Loop to move the value up the tree until the heap property is restored
    while (index > 0 && heap[index] < heap[(index - 1) / 2]) {
        std::swap(heap[index], heap[(index - 1) / 2]); // Swap with parent
        index = (index - 1) / 2; // Move up to the parent node
    }
}
