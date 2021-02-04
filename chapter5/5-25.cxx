#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <stdexcept>
using std::runtime_error;

void getI2(int *i) {
  cout << "Enter the second integer:" << endl;
  cin >> *i;
}

int main() {
  int i1, i2;
  float f;
  cout << "Enter an integer:" << endl;
  cin >> i1;

  try {
    getI2(&i2);
    if (i2 == 0) {
      throw runtime_error("i2 cannot be 0");
    }
  } catch (runtime_error err) {
    cout << "Caugth runtime_error with message " << err.what() << endl;
    while (i2 == 0) {
      cout << " Please enter a valid number for i2" << endl;
      getI2(&i2);
    }
  }

  f = static_cast<float>(i1) / i2;
  cout << i1 << "/" << i2 << "=" << f << endl;
  return 0;
}
