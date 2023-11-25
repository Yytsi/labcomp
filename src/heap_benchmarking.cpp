#include "../src/binary_heap.cpp"
#include "../src/binomial_heap.cpp"
#include "../src/d_ary_heap.cpp"
#include "../src/pairing_heap.cpp"
#include <vector>
#include <iostream>
#include <chrono>
#include <typeinfo>

using namespace std;
using namespace std::chrono;

template<typename HeapType>
void testHeapWithInput(HeapType& heap, const vector<pair<char, int>>& actions) {
    auto start = high_resolution_clock::now();

    for (auto& k : actions) {
        char s = k.first;
        int num = k.second;
        if (s == 'a') {
            heap.insert(num);
        } else if (s == 'p') {
            heap.deleteMinimum();
        } else if (s == 'g') {
            heap.getMinimum();
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << typeid(HeapType).name() << ": " << duration.count() << " mikrosekuntia" << endl;
    cout << typeid(HeapType).name() << ": " << duration.count()/1000000.0 << " sekuntia" << endl;
}

int main() {
    int n;
    cin >> n;

    vector<pair<char, int>> actions;
    for (int i = 0; i < n; i++) {
        char s;
        cin >> s;
        int x = -1;
        if (s == 'a') {
            cin >> x;
        }
        actions.push_back({s, x});
    }

    BinaryHeap binaryHeap;
    BinomialHeap binomialHeap;
    DaryHeap daryHeap(4); // Create a D-ary heap with D = 4
    PairingHeap pairingHeap;

    testHeapWithInput(binaryHeap, actions);
    testHeapWithInput(binomialHeap, actions);
    testHeapWithInput(daryHeap, actions);
    testHeapWithInput(pairingHeap, actions);
}
