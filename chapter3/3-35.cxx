#include <iostream>
using std::cout;
using std::endl;

#include <cstdint>
using std::size_t;

#include <vector>
using std::vector;

#include <iterator>
using std::end;

int main() {
  constexpr size_t sa = 3;
  int ia[sa] = {1, 2, 3};

  cout << "Using end(ia)" << endl;
  int c = 1;
  for (int *p = &ia[0]; p != end(ia); ++p, ++c) {
    *p = 0;
    cout << "Number of times in loop: " << c << endl;
  }
  for (auto i : ia) {
    cout << i << endl;
  }

  cout << "Using p - &ia[sa] != 0 comparison" << endl;
  c = 1;
  for (int *p = &ia[0]; p - &ia[sa] != 0; ++p, ++c) {
    *p = 99;
    cout << "Number of times in loop: " << c << endl;
  }
  for (auto i : ia) {
    cout << i << endl;
  }
  return 0;
}
