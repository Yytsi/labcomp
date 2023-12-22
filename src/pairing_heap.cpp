#include "../include/pairing_heap.hpp"
#include <memory>
#include <stdexcept>

void PairingHeap::insert(int value) {
    std::shared_ptr<PairingHeapNode> newNode = std::make_shared<PairingHeapNode>(value);
    // Merge the new node with the existing heap.
    root = merge(root, newNode);
}

int PairingHeap::getMinimum() const {
    if (!root) throw std::runtime_error("Tyhjästä parituskeosta minimi.");
    return root->value;
}

void PairingHeap::deleteMinimum() {
    if (!root) throw std::runtime_error("Tyhjästä parituskeosta minimin poistaminen.");
    // Merge the pairs of children of the root to form a new heap.
    root = mergePairs(root->child);
}

// Merge two heaps together
std::shared_ptr<PairingHeapNode> PairingHeap::merge(std::shared_ptr<PairingHeapNode> a, std::shared_ptr<PairingHeapNode> b) {
    // Handle cases where one or both heaps are empty.
    if (!a) return b;
    if (!b) return a;

    // Compare root values and rearrange nodes to maintain heap property.
    if (a->value < b->value) {
        b->sibling = a->child;
        a->child = b;
        return a;
    } else {
        a->sibling = b->child;
        b->child = a;
        return b;
    }
}

// Merge pairs of nodes in the heap.
std::shared_ptr<PairingHeapNode> PairingHeap::mergePairs(std::shared_ptr<PairingHeapNode> first) {
    if (!first || !first->sibling) return first;

    // Split the siblings and merge them separately.
    std::shared_ptr<PairingHeapNode> second = first->sibling;
    std::shared_ptr<PairingHeapNode> rest = second->sibling;

    first->sibling = nullptr;
    second->sibling = nullptr;

    // Recursively merge the pairs and their result with the rest.
    return merge(merge(first, second), mergePairs(rest));
}
