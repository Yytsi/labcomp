#include <memory>

struct PairingHeapNode {
    int value;
    std::shared_ptr<PairingHeapNode> child;
    std::shared_ptr<PairingHeapNode> sibling;

    explicit PairingHeapNode(int val) : value(val), child(nullptr), sibling(nullptr) {}
};

class PairingHeap {
public:
    PairingHeap() : root(nullptr) {}
    void insert(int value);
    int getMinimum() const;
    void deleteMinimum();

private:
    

    std::shared_ptr<PairingHeapNode> root;
    std::shared_ptr<PairingHeapNode> merge(std::shared_ptr<PairingHeapNode> a, std::shared_ptr<PairingHeapNode> b);

    std::shared_ptr<PairingHeapNode> mergePairs(std::shared_ptr<PairingHeapNode> first);
};