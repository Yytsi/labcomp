#include <vector>

class BinaryHeap {
private:
  std::vector<int> heap;

public:
  void insert(int value);
  int getMinimum() const;
  void deleteMinimum();
  void heapifyDown(int index);
  void heapifyUp(int index);
};