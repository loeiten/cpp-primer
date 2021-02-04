#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void swap(int& a, int& b) {
  int dummy = a;
  a = b;
  b = dummy;
}

int main() {
  int a;
  int b;
  cout << "Inster number of a:" << endl;
  cin >> a;
  cout << "Inster number of b:" << endl;
  cin >> b;

  cout << "Before swap: a=" << a << ", b=" << b << endl;

  swap(a, b);
  cout << "After swap: a=" << a << ", b=" << b << endl;
  return 0;
}
