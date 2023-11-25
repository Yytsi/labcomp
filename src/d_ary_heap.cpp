#include "../include/d_ary_heap.hpp"
#include <stdexcept>

void DaryHeap::insert(int v) {
  heap.push_back(v);
  heapifyUp(heap.size() - 1);
}

// Returns the minimum value in the heap
int DaryHeap::getMinimum() const {
  if (heap.empty()) throw std::runtime_error("Tyhjästä D-ary keosta minimi.");
  return heap[0]; // Return the minimum value
}

// Deletes the minimum value from the heap
void DaryHeap::deleteMinimum() {
  if (heap.empty()) throw std::runtime_error("Tyhjästä D-ary keosta haku.");
  heap[0] = heap.back(); // Replace root with the last element
  heap.pop_back();
  heapifyDown(0);
}


int DaryHeap::getParent(int idx) const {
  return (idx - 1) / d;
}

// Retrieves the nth child of a given index in the heap
int DaryHeap::getNthChild(int idx, int n) const {
  return d * idx + n;
}

// Ensure the heap maintains its properties after insertion
void DaryHeap::heapifyUp(int idx) {
  // Continues until the root or correct order is found
  while (idx > 0 && heap[getParent(idx)] > heap[idx]) {
    std::swap(heap[idx], heap[getParent(idx)]);
    idx = getParent(idx); // Move to parent index
  }
}

// Ensure the heap maintains its properties after deletion
void DaryHeap::heapifyDown(int idx) {
  int minv = idx;
  // Check children and find the minimum value
  for (int k = 1; k <= d; k++) {
    int ch = getNthChild(idx, k);
    if (ch < heap.size() && heap[ch] < heap[minv]) {
      minv = ch; // Update minimum value index
    }
  }
  // Swap and continue heapifying down if needed
  if (minv != idx) {
    std::swap(heap[idx], heap[minv]);
    heapifyDown(minv);
  }
}

