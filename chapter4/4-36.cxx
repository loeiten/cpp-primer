#include <iostream>
using std::cout;
using std::endl;

int main() {
  int i = 2;
  double d = 2.6;

  double r = i * d;
  cout << "Double multiplication results in: r = " << r << endl;

  // Resetting i
  i *= static_cast<int>(d);
  cout << "Int multiplication results in: i = " << i << endl;

  return 0;
}
