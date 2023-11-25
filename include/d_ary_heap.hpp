#include <vector>

class DaryHeap {
private:
    std::vector<int> heap;
    int d;

    int getParent(int idx) const;
    int getNthChild(int idx, int n) const;

    void heapifyUp(int idx);
    void heapifyDown(int idx);
public:
    explicit DaryHeap(int d) : d(d) {}
    void insert(int v);
    int getMinimum() const;
    void deleteMinimum();
};
