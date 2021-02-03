#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;

int main() {
  int ival = 0, ival2 = 0;
  int* ptr = &ival2;
  vector<int> vec{0, 1, 2, 3, 4, 5};

  if (ptr != 0) {
    cout << "'ptr != 0', even though *ptr = " << *ptr << endl;
  }

  cout << "'ptr != 0 && *ptr++' will return false as *ptr = " << *ptr << endl;
  if (ptr != 0 && *ptr++) {
    cout << "WOW...MAJOR FAIL: 'ptr != 0 && *ptr++' was for some reason 'true'"
         << *ptr << endl;
  }

  if (ptr != 0 && *ptr++) {
    cout << "The second 'ptr != 0 && *ptr++' gives undefined behaviour as we "
            "increment the pointer above it's end, i.e. *ptr = "
         << *ptr << endl;
  }

  cout << "'ival++ && ival' will return false as ival = " << ival << endl;
  if (ival++ && ival) {
    cout << "WOW...MAJOR FAIL: 'ival++ && ival' was for some reason 'true'"
         << ival << endl;
  }
  if (ival++ && ival) {
    cout << "The second 'ival++ && ival' is true as ival was incremented to 1 "
            "previously, and has been incremented again to "
         << ival << endl;
  }

  // NOTE: We cast ival_size to size_t in order not to get implicit conversion
  // changes signedness
  size_t ival_size = static_cast<std::vector<int>::size_type>(ival);
  cout << "ival_size = " << ival_size
       << " and vec[ival_size] = " << vec[ival_size] << endl;
  /*
  if(vec[ival_size++] <= vec[ival_size]){
    cout << "Undefiend behaviour as both operands uses ival_size, and operators
  does not guarantee orded of operand evaluation" << endl;
  }
  */

  return 0;
}
