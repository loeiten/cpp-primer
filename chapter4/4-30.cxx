#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::fill;
using std::vector;

void print_vec(vector<uint64_t>* vec) {
  for (auto it = vec->begin(); it != vec->end(); ++it) {
    cout << *it << endl;
  }
}

int main() {
  vector<uint64_t> ivec(5, 99);

  cout << "\nOriginal vector:" << endl;
  print_vec(&ivec);

  uint64_t cnt = ivec.size();
  for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt) {
    ivec[ix] = cnt;
  }

  cout << "\nPrefix increment:" << endl;
  print_vec(&ivec);

  // Remember to reset cnt and ivec
  cnt = ivec.size();
  fill(ivec.begin(), ivec.end(), 99);
  cout << "\nVector after reset:" << endl;
  print_vec(&ivec);

  for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--) {
    ivec[ix] = cnt;
  }
  cout << "\nPostfix increment:" << endl;
  print_vec(&ivec);

  return 0;
}
