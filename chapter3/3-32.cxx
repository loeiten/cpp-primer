#include <iostream>
using std::cout;
using std::endl;

#include <cstdint>
using std::size_t;

#include <vector>
using std::vector;

int main() {
  constexpr size_t kArraySize = 10;
  size_t ia[kArraySize];
  for (size_t ix = 0; ix < kArraySize; ++ix) {
    ia[ix] = ix;
  }
  cout << "Printing original array" << endl;
  for (size_t ix = 0; ix < kArraySize; ++ix) {
    cout << ix << ": " << ia[ix] << endl;
  }
  size_t acopy[kArraySize];
  for (size_t ix = 0; ix < kArraySize; ++ix) {
    acopy[ix] = ix;
  }
  cout << "Printing copy" << endl;
  for (size_t ix = 0; ix < kArraySize; ++ix) {
    cout << ix << ": " << acopy[ix] << endl;
  }

  vector<size_t> iv;
  for (size_t ix = 0; ix < kArraySize; ++ix) {
    iv.push_back(ix);
  }
  cout << "Printing original array" << endl;
  for (size_t ix = 0; ix < kArraySize; ++ix) {
    cout << ix << ": " << iv[ix] << endl;
  }
  vector<size_t> vcopy;
  for (size_t ix = 0; ix < kArraySize; ++ix) {
    vcopy.push_back(ix);
  }
  cout << "Printing copy" << endl;
  for (size_t ix = 0; ix < kArraySize; ++ix) {
    cout << ix << ": " << vcopy[ix] << endl;
  }
  return 0;
}
