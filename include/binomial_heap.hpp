#include <list>
#include <memory>
#include <algorithm>
#include <stdexcept>

class BinomialHeapNode {
public:
    int data;
    int degree;
    std::shared_ptr<BinomialHeapNode> child;
    std::shared_ptr<BinomialHeapNode> sibling;

    explicit BinomialHeapNode(int data)
        : data(data), degree(0), child(nullptr), sibling(nullptr) {}
};

class BinomialHeap {
public:
    std::list<std::shared_ptr<BinomialHeapNode>> roots;

    std::shared_ptr<BinomialHeapNode> mergeTrees(std::shared_ptr<BinomialHeapNode> a, std::shared_ptr<BinomialHeapNode> b);
    void merge(BinomialHeap& other);
    void heapify();
    void insert(int value);
    int getMinimum();
    void deleteMinimum();

    BinomialHeap() = default;
    ~BinomialHeap() = default;
};
