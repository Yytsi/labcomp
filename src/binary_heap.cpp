#include "../include/binary_heap.hpp"
#include <stdexcept>

using namespace std;

// Using a standard implementation, will switch to pointers later

void BinaryHeap::insert(int val) {
  heap.push_back(val);
  heapifyUp(heap.size() - 1); // Guarantee heap structure
}

int BinaryHeap::getMinimum() {
  if (heap.empty()) throw runtime_error("Tyhjästä keosta otettu arvo.");
  return heap[0];
}

void BinaryHeap::deleteMinimum() {
  if (heap.empty()) throw runtime_error("Tyhjästä keosta poisto.");
  heap[0] = heap.back();
  heap.pop_back();
  if (heap.size()) heapifyDown(0); // Guarantee heap structure by heapifying down from root
}

void BinaryHeap::heapifyDown(int idx) {
  // find smallest children and swap with it if necessary
  int smallest = idx;

  int leftChild = 2*idx+1;
  int rightChild = 2*idx+2;

  if (leftChild < (int)heap.size() && heap[leftChild] < heap[smallest]) smallest = leftChild;
  if (rightChild < (int)heap.size() && heap[rightChild] < heap[smallest]) smallest = rightChild;

  if (idx < smallest) {
    swap(heap[idx], heap[smallest]);
    heapifyDown(smallest);
  }
}

void BinaryHeap::heapifyUp(int idx) {
  // As long as parent is bigger than this, swap with it
  while (idx && heap[idx] < heap[(idx - 1) / 2]) {
    swap(heap[idx], heap[(idx - 1) / 2]);
    idx = (idx - 1) / 2;
  }
}