#include "../include/binomial_heap.hpp"

void BinomialHeap::insert(int value) {
    BinomialHeap tempHeap;
    tempHeap.roots.push_back(std::make_shared<BinomialHeapNode>(value));
    merge(tempHeap);
    heapify();
}

int BinomialHeap::getMinimum() {
    if (roots.empty()) throw std::runtime_error("Tyhjästä binomiaalisesta keosta minimi.");

    int min = roots.front()->data;
    for (const auto& root : roots) {
        if (root->data < min) min = root->data;
    }
    return min;
}

// Deletes the minimum element from the heap
void BinomialHeap::deleteMinimum() {
    if (roots.empty()) throw std::runtime_error("Tyhjästä binomiaalisesta keosta poisto.");

    // Finding a tree with minimum root
    auto minIt = roots.begin();
    for (auto it = roots.begin(); it != roots.end(); ++it) {
        if ((*it)->data < (*minIt)->data) {
            minIt = it;
        }
    }
    BinomialHeap tempHeap;
    
    // Separating children of the minimum node
    std::shared_ptr<BinomialHeapNode> minNode = *minIt;
    std::shared_ptr<BinomialHeapNode> child = minNode->child;
    while (child) {
        std::shared_ptr<BinomialHeapNode> next = child->sibling;
        child->sibling = nullptr;
        tempHeap.roots.push_front(child);
        child = next;
    }

    roots.erase(minIt);
    merge(tempHeap);
    heapify();
}

// Merges two binomial trees of the same degree. Returns the merged tree.
std::shared_ptr<BinomialHeapNode> BinomialHeap::mergeTrees(std::shared_ptr<BinomialHeapNode> a, std::shared_ptr<BinomialHeapNode> b) {
    if (a->data > b->data) std::swap(a, b);
    
    b->sibling = a->child;
    a->child = b;
    a->degree++;
    return a;
}

// Merges the current heap with another heap
void BinomialHeap::merge(BinomialHeap& other) {
    auto it1 = roots.begin(), it2 = other.roots.begin();
    // Compare and merge roots of the two heaps
    while (it1 != roots.end() && it2 != other.roots.end()) {
        if ((*it1)->degree < (*it2)->degree) {
            ++it1;
        } else if ((*it1)->degree > (*it2)->degree) {
            roots.insert(it1, *it2);
            ++it2;
        } else {
            *it1 = mergeTrees(*it1, *it2);
            it2 = other.roots.erase(it2);
        }
    }
    // If there are still elements in the other heap, add them to the current heap
    if (it2 != other.roots.end()) {
        roots.insert(roots.end(), it2, other.roots.end());
    }
}

// Ensure the heap maintains its properties after merging
void BinomialHeap::heapify() {
    if (roots.empty()) return;

    auto prev = roots.begin();
    auto curr = std::next(prev);
    while (curr != roots.end()) {
        if ((*prev)->degree != (*curr)->degree) {
            prev = curr;
            ++curr;
        } else if (std::next(curr) != roots.end() && (*std::next(curr))->degree == (*curr)->degree) {
            prev = curr;
            ++curr;
        } else {
            *prev = mergeTrees(*prev, *curr);
            curr = roots.erase(curr);
        }
    }
}