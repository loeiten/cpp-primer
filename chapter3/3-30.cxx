#include <iostream>
using std::cout;
using std::endl;

#include <cstdint>
using std::size_t;

int main() {
  constexpr size_t kArraySize = 10;
  // NOTE: Added +1 as we subscript ix <= kArraySize
  int ia[kArraySize + 1];
  for (size_t ix = 1; ix <= kArraySize; ++ix) {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
    // NOTE: size_t can usually express larger numbers than int
    ia[ix] = ix + 1;
#pragma clang diagnostic pop
    if (ix >= kArraySize) {
      ia[ix] = -99;
    }
  }
  for (size_t ix = 0; ix <= kArraySize; ++ix) {
    cout << ix << ": " << ia[ix] << endl;
  }
  return 0;
}
