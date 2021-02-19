#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>
using std::unique_copy;

#include <iterator>
using std::back_inserter;

#include <vector>
using std::vector;

#include <list>
using std::list;

template <typename Iter>
void print(Iter it, Iter end) {
  for (; it != end; ++it) {
    cout << *it << endl;
  }
}

int main() {
  vector<int> vi;
  vector<int> vic;
  list<int> li;

  for (int i = 0; i <= 9; ++i) {
    vi.push_back(i);
    vi.push_back(i % 3);
  }
  cout << "Printing vector" << endl;
  print(vi.begin(), vi.end());

  sort(vi.begin(), vi.end());
  cout << "\nPrinting vector after sorting" << endl;
  print(vi.begin(), vi.end());

  unique_copy(vi.begin(), vi.end(), back_inserter(vic));
  cout << "\nPrinting vector unique copy" << endl;
  print(vic.begin(), vic.end());

  copy(vic.begin(), vic.end(), back_inserter(li));
  cout << "\nPrinting after copying to list" << endl;
  print(li.begin(), li.end());
  return 0;
}
