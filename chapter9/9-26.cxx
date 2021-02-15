#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <iterator>
using std::begin;
using std::end;

int main() {
  int ia[]{0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
  vector<int> vi(begin(ia), end(ia));
  list<int> li(begin(ia), end(ia));

  // We use a while loop as "i" will be invalidated after erasing the element
  // https://stackoverflow.com/questions/5295373/cppcheck-error-dangerous-iterator-usage
  auto vii = vi.begin();
  while (vii != vi.end()) {
    if (!(*vii % 2)) {
      vii = vi.erase(vii);  // Remove even values
    } else {
      ++vii;  // Advance the iterator
    }
  }

  auto lii = li.begin();
  while (lii != li.end()) {
    if (*lii % 2) {
      lii = li.erase(lii);  // Remove odd values
    } else {
      ++lii;  // Advance the iterator
    }
  }

  cout << "Odd:" << endl;
  for (const auto &el : vi) {
    cout << el << endl;
  }

  cout << "\nEven:" << endl;
  for (const auto &el : li) {
    cout << el << endl;
  }

  return 0;
}
