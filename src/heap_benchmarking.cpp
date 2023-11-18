#include "../src/binary_heap.cpp"
#include <string>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void testWithInput(vector<pair<char, int>> actions) {
  auto start = high_resolution_clock::now();

  BinaryHeap bin;
  for (pair<char, int> k : actions) {
    char s = k.first;
    int num = k.second;
    if (s == 'a') {
      bin.insert(num);
    } else if (s == 'p') {
      bin.deleteMinimum();
    } else if (s == 'g') {
      bin.getMinimum();
    }
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Testi vei aikaa: " << duration.count() << " mikrosekuntia" << endl;
  cout << "Testi vei aikaa: " << duration.count()/1000000.0 << " sekuntia" << endl;
}

int main() {
  int n;
  cin>>n;

  vector<pair<char, int>> actions;

  for (int i = 0; i < n; i++) {
    char s;
    cin>>s;
    
    if (s == 'a') {
      int x;
      cin>>x;
      actions.push_back({s, x});
    } else actions.push_back({s, -1});
  }

  testWithInput(actions);
}