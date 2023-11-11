#include <queue>
#include <vector>
#include <functional>

using namespace std;

#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

class BinaryHeap {
private:
  vector<int> heap;

public:
  void insert(int key);
  int getMinimum();
  void deleteMinimum();
  void heapifyDown(int idx);
  void heapifyUp(int idx);
};

#endif // BINARY_HEAP_H
