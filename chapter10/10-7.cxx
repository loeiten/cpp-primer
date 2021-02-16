#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <algorithm>
using std::fill_n;

#include <iterator>
using std::back_inserter;

#include <vector>
using std::vector;

#include <list>
using std::list;

int main() {
  vector<int> vec;
  list<int> lst;
  int i;
  cout << "Enter a couple of ints" << endl;
  while (cin >> i) {
    lst.push_back(i);
  }
  // copy(lst.cbegin(), lst.cend(), vec.begin());  // No elements exist in vec
  copy(lst.cbegin(), lst.cend(), back_inserter(vec));

  cout << "\nVector copied from list" << endl;
  for (const auto el : vec) {
    cout << el << endl;
  }

  vector<int> vec2;
  // vec.reserve(10);  // Reserve will only allocate memory, but not add any
  // elements
  vec2.resize(10);
  fill_n(vec2.begin(), 10, 0);

  cout << "\nDifferent filled vector" << endl;
  for (const auto el : vec2) {
    cout << el << endl;
  }
  return 0;
}
