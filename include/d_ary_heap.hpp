#include <vector>

class DaryHeap {
private:
    std::vector<int> heap;
    int degree;

    int getParent(int node_index) const;
    int getNthChild(int index, int n) const;

    void heapifyUp(int node_index);
    void heapifyDown(int node_index);
public:
    explicit DaryHeap(int degree) : degree(degree) {}
    void insert(int value);
    int getMinimum() const;
    void deleteMinimum();
};
