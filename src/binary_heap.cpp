#include "../include/binary_heap.hpp"
#include <stdexcept>

void BinaryHeap::insert(int val) {
  heap.push_back(val);
  heapifyUp(heap.size() - 1); // Maintain heap order after insertion
}

int BinaryHeap::getMinimum() const {
  if (heap.empty()) throw std::runtime_error("Tyhjästä binäärikeosta minimi.");
  return heap[0];
}

void BinaryHeap::deleteMinimum() {
  if (heap.empty()) throw std::runtime_error("Tyhjästä binäärikeosta poisto.");
  heap[0] = heap.back();
  heap.pop_back();
  if (!heap.empty()) heapifyDown(0); // Maintain heap order after deletion
}

void BinaryHeap::heapifyDown(int idx) {
  int smallest = idx;
  int leftChild = 2 * idx + 1;
  int rightChild = 2 * idx + 2;

  if (leftChild < static_cast<int>(heap.size()) && heap[leftChild] < heap[smallest]) {
    smallest = leftChild;
  }
  if (rightChild < static_cast<int>(heap.size()) && heap[rightChild] < heap[smallest]) {
    smallest = rightChild;
  }

  if (smallest != idx) {
    std::swap(heap[idx], heap[smallest]);
    heapifyDown(smallest);
  }
}

void BinaryHeap::heapifyUp(int idx) {
  while (idx > 0 && heap[idx] < heap[(idx - 1) / 2]) {
    std::swap(heap[idx], heap[(idx - 1) / 2]);
    idx = (idx - 1) / 2;
  }
}
