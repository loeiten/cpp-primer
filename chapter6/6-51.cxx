#include <iostream>
using std::cout;
using std::endl;

inline void f() { cout << "f() called" << endl; }

inline void f(int) { cout << "f(int) called" << endl; }

inline void f(int, int) { cout << "f(int, int) called" << endl; }

inline void f(double, double = 3.14) {
  cout << "f(double, double = 3.14) called" << endl;
}

int main() {
  // f(2.54, 42); // Ambiguous
  f(42);
  f(42, 0);
  f(2.56, 3.14);
  return 0;
}
