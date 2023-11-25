#include <vector>

class BinaryHeap {
private:
  std::vector<int> heap;

public:
  void insert(int val);
  int getMinimum() const;
  void deleteMinimum();
  void heapifyDown(int idx);
  void heapifyUp(int idx);
};