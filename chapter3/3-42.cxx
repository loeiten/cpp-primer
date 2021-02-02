#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <iterator>
using std::begin;
using std::end;

#include <algorithm>
using std::copy;

int main() {
  int ia[] = {1, 2, 3};
  // Initialize with begin, end
  vector<int> iv(begin(ia), end(ia));

  cout << "Printing iv" << endl;
  for (auto i : iv) {
    cout << i << endl;
  }

  iv.push_back(99);

  // NOTE: int ia2[iv.size()] is not allowed since this gives a variable-length
  // array
  int *ia2;
  ia2 = new int[iv.size()];
  copy(iv.begin(), iv.end(), ia2);

  cout << "Printing ia2" << endl;
  for (size_t i = 0; i != iv.size(); ++i) {
    cout << ia2[i] << endl;
  }

  delete ia2;
  return 0;
}
