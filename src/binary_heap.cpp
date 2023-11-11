#include "../include/binary_heap.hpp"

using namespace std;

// using a standard implementation, will switch to pointers later

void BinaryHeap::insert(int val) {
  heap.push_back(val);
  heapifyUp(heap.size() - 1);
}

int BinaryHeap::getMinimum() {
  if (heap.empty()) throw runtime_error("Tyhjästä keosta otettu arvo.");
  return heap[0];
}

void BinaryHeap::deleteMinimum() {
  if (heap.empty()) throw runtime_error("Tyhjästä keosta poisto.");
  heap[0] = heap.back();
  heap.pop_back();
  if (heap.size()) heapifyDown(0);
}

void BinaryHeap::heapifyDown(int idx) {
  // find smallest children and swap with it if necessary
  int smallest = idx;

  if (2*idx+1 < (int)heap.size() && heap[2*idx+1] < heap[smallest]) smallest = 2*idx+1;
  if (2*idx+2 < (int)heap.size() && heap[2*idx+2] < heap[smallest]) smallest = 2*idx+2;

  if (idx < smallest) {
    swap(heap[idx], heap[smallest]);
    heapifyDown(smallest);
  }
}

void BinaryHeap::heapifyUp(int idx) {
  // as long as parent is bigger than this, swap with it
  while (idx && heap[idx] < heap[(idx - 1) / 2]) {
    swap(heap[idx], heap[(idx - 1) / 2]);
    idx = (idx - 1) / 2;
  }
}