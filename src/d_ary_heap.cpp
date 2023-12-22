#include "../include/d_ary_heap.hpp"
#include <stdexcept>

// Inserts a new value into the heap.
// value: The value to be inserted.
void DaryHeap::insert(int value) {
  heap.push_back(value); // Add the value to the end of the heap.
  heapifyUp(heap.size() - 1); // Maintain heap properties after insertion.
}

// Returns the minimum value in the heap.
// throws: std::runtime_error if the heap is empty.
int DaryHeap::getMinimum() const {
  if (heap.empty()) throw std::runtime_error("Tyhjästä D-ary keosta minimi.");
  return heap[0]; // Return the minimum value.
}

// Deletes the minimum value from the heap.
// throws: std::runtime_error if the heap is empty.
void DaryHeap::deleteMinimum() {
  if (heap.empty()) throw std::runtime_error("Tyhjästä D-ary keosta haku.");
  heap[0] = heap.back(); // Replace root with the last element.
  heap.pop_back(); // Remove the last element.
  heapifyDown(0); // Maintain heap properties after deletion.
}

// Retrieves the parent of a given index in the heap.
int DaryHeap::getParent(int node_index) const {
  return (node_index - 1) / degree;
}

// Retrieves the nth child of a given index in the heap.
int DaryHeap::getNthChild(int index, int n) const {
  return degree * index + n;
}

// Ensure the heap maintains its properties after insertion.
void DaryHeap::heapifyUp(int node_index) {
  // Continues until the root or correct order is found.
  while (node_index > 0 && heap[getParent(node_index)] > heap[node_index]) {
    std::swap(heap[node_index], heap[getParent(node_index)]);
    node_index = getParent(node_index); // Move to parent index.
  }
}

// Ensure the heap maintains its properties after deletion.
void DaryHeap::heapifyDown(int index) {
  int minv = index;
  // Check children and find the minimum value.
  for (int k = 1; k <= degree; k++) {
    int kth_child = getNthChild(index, k);
    if (kth_child < heap.size() && heap[kth_child] < heap[minv]) {
      minv = kth_child; // Update minimum value index.
    }
  }
  // Swap and continue heapifying down if needed.
  if (minv != index) {
    std::swap(heap[index], heap[minv]); // Swap if a smaller value was found.
    heapifyDown(minv); // Continue heapifying down.
  }
}

