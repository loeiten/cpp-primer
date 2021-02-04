#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

void print_v_recursively(const vector<int>::iterator& it,
                         const vector<int>::iterator& end) {
  if (it != end) {
    cout << *it << endl;
    print_v_recursively(it + 1, end);
  }
}

int main() {
  vector<int> iv{42, 54, 7};

  print_v_recursively(iv.begin(), iv.end());
  return 0;
}
