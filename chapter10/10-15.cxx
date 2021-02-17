#include <iostream>
using std::cout;
using std::endl;

int main() {
  int a = 2;
  auto f = [a](const int& b) -> int { return a + b; };
  cout << f(5) << endl;
  return 0;
}
