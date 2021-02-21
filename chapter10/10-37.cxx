#include <iostream>
using std::cout;
using std::endl;

#include <iterator>
using std::back_inserter;

#include <list>
using std::list;

#include <vector>
using std::vector;

#include <algorithm>
using std::copy;

template <typename Iter>
void print(Iter it, Iter end) {
  for (; it != end; ++it) {
    cout << *it << endl;
  }
}

int main() {
  vector<int> vi;
  list<int> li;

  for (int i = 1; i <= 10; ++i) {
    vi.push_back(i);
  }
  cout << "Original vector" << endl;
  print(vi.begin(), vi.end());

  /*
   * NOTE: Copy will not copy the normal .end() element which denotes one pass
   * the first element Thus copy will stop copy at index 0 (= position 1)
   *       Subtracting 2 to index 0 gives position 3
   */
  copy(vi.crbegin() + 3, vi.crend() - 2, back_inserter(li));
  cout << "\nreverse list" << endl;
  print(li.begin(), li.end());

  return 0;
}
