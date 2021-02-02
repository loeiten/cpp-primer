#include <iostream>
using std::cout;
using std::endl;

int main() {
  int i = 2;
  // if (42 = i)  // Not modifiable lvalue
  if ((i = 42)) {
    cout << i << endl;
  }
  return 0;
}
