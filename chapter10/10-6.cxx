#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>
using std::fill_n;

#include <iterator>
using std::back_inserter;

#include <vector>
using std::vector;

int main() {
  vector<int> v;

  fill_n(back_inserter(v), 7, 0);

  for (const auto el : v) {
    cout << el << endl;
  }
  return 0;
}
