#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

void print_v_recursively(const vector<int>::iterator& it,
                         const vector<int>::iterator& end) {
  if (it != end) {
    cout << *it << endl;
#ifdef NDEBUG
    cerr << "Debug at " << __DATE__ << " at " << __TIME__
         << " from: " << __func__ << " in " << __FILE__ << " at line "
         << __LINE__ << "\nCurrent length = " << end - it << endl;
#endif
    print_v_recursively(it + 1, end);
  }
}

/*
Compile with
clang++ -std=c++14 -Wall -Wextra -Werror -Wshadow -Wdouble-promotion -Wformat=2
-Wundef -Wconversion -g3 -Os -D NDEBUG -o 6-47 6-47.cxx && ./6-47
*/
int main() {
  vector<int> iv{42, 54, 7};

  print_v_recursively(iv.begin(), iv.end());
  return 0;
}
