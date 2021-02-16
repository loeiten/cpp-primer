#include <iostream>
using std::cout;
using std::endl;

#include <forward_list>
using std::forward_list;

void print(const forward_list<unsigned int>& fl) {
  for (const auto& el : fl) {
    cout << el << endl;
  }
}

int main() {
  forward_list<unsigned int> fi;
  auto prev = fi.before_begin();

  // Populate the list
  for (unsigned int i = 0; i <= 9; ++i) {
    fi.insert_after(prev, i);
    ++prev;
  }

  cout << "Before delete:" << endl;
  print(fi);

  // Delete
  prev = fi.before_begin();
  auto cur = fi.begin();
  while (cur != fi.end()) {
    if (*cur % 2) {
      cur = fi.erase_after(prev);
    } else {
      prev = cur;
      ++cur;
    }
  }

  cout << "\nAfter delete:" << endl;
  print(fi);

  return 0;
}
