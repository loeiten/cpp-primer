#include <iostream>
using std::cout;
using std::endl;

int main() {
  int a = 22;

  auto f = [&a]() -> bool {
    if (a > 0) {
      --a;
    }
    return a == 0;
  };

  cout << "Initial value of a: " << a << endl;
  while (a != 0) {
    f();
    cout << "Current value of a: " << a << endl;
  }
  f();
  cout << "End value of a: " << a << endl;
  return 0;
}
