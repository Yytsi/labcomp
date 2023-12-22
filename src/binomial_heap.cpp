#include "../include/binomial_heap.hpp"

// Inserts a new value into the binomial heap.
// value: The integer value to be inserted into the heap.
void BinomialHeap::insert(int value) {
    BinomialHeap tempHeap;
    tempHeap.roots.push_back(std::make_shared<BinomialHeapNode>(value)); // Create a new heap with the value
    merge(tempHeap); // Merge the new heap with the existing one
    heapify(); // Rearrange to maintain heap properties
    updateMinNode(); // Update the minimum node
}

// Retrieves the minimum value from the heap.
// Returns: The minimum integer value in the heap.
// Throws: std::runtime_error if the heap is empty.
int BinomialHeap::getMinimum() {
    if (!minNode) throw std::runtime_error("Heap is empty. Cannot get minimum.");
    return minNode->data;
}

// Deletes the minimum element from the heap.
// Throws: std::runtime_error if the heap is empty.
void BinomialHeap::deleteMinimum() {
    if (roots.empty()) throw std::runtime_error("Heap is empty. Cannot delete minimum.");

    // Find the minimum root by iterating through the roots.
    auto minIt = roots.begin();
    for (auto it = roots.begin(); it != roots.end(); ++it) {
        if ((*it)->data < (*minIt)->data) {
            minIt = it;
        }
    }

    BinomialHeap tempHeap;
    std::shared_ptr<BinomialHeapNode> minNode = *minIt;
    std::shared_ptr<BinomialHeapNode> child = minNode->child;
    while (child) {
        std::shared_ptr<BinomialHeapNode> next = child->sibling;
        child->sibling = nullptr; // Detach the child from its sibling.
        tempHeap.roots.push_front(child); // Add child to the temporary heap.
        child = next; // Move to the next sibling.
    }

    roots.erase(minIt); // Remove the minimum node from the roots.
    merge(tempHeap); // Merge the temporary heap with the current heap.
    heapify(); // Rearrange to maintain heap properties.
    updateMinNode(); // Update the minimum node.
}

// Merges two binomial trees of the same degree.
// a, b: Shared pointers to the binomial heap nodes to be merged.
// Returns: A shared pointer to the merged binomial heap node.
std::shared_ptr<BinomialHeapNode> BinomialHeap::mergeTrees(std::shared_ptr<BinomialHeapNode> a, std::shared_ptr<BinomialHeapNode> b) {
    if (a->data > b->data) std::swap(a, b); // Ensure 'a' has the smaller root
    
    b->sibling = a->child; // Link the child of 'a' as the sibling of 'b'
    a->child = b; // Make 'b' the child of 'a'
    a->degree++; // Increment the degree of 'a'
    return a; // Return the merged tree.
}

// Merges the current heap with another heap.
// other: Reference to the binomial heap to be merged with.
void BinomialHeap::merge(BinomialHeap& other) {
    auto it1 = roots.begin(), it2 = other.roots.begin();
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
    if (it2 != other.roots.end()) {
        roots.insert(roots.end(), it2, other.roots.end());
    }
    updateMinNode(); // Update the minimum node.
}

// Ensures the heap maintains its properties after other operations like insertions or deletions.
void BinomialHeap::heapify() {
    if (roots.empty()) return;

    auto prev = roots.begin();
    auto curr = std::next(prev);
    while (curr != roots.end()) {
        // Merge trees if they have the same degree, except when the next tree also has the same degree.
        // Otherwise move to the next tree
        // This is done to ensure that the roots are in increasing order of degree.
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

void BinomialHeap::updateMinNode() {
    minNode = nullptr;
    for (const auto& root : roots) {
        if (!minNode || root->data < minNode->data) {
            minNode = root;
        }
    }
}