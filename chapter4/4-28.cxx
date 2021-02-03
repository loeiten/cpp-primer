#include <iostream>
using std::cout;
using std::endl;

int main() {
  cout << "sizeof(nullptr) = " << sizeof(nullptr) << endl;
  cout << "sizeof(bool) = " << sizeof(bool) << endl;
  cout << "sizeof(short int) = " << sizeof(short int) << endl;  // NOLINT
  cout << "sizeof(int) = " << sizeof(int) << endl;
  cout << "sizeof(unsigned int) = " << sizeof(unsigned int) << endl;
  cout << "sizeof(long int) = " << sizeof(long int) << endl;           // NOLINT
  cout << "sizeof(unsigned long int) = " << sizeof(unsigned long int)  // NOLINT
       << endl;
  cout << "sizeof(long long int) = " << sizeof(long long int)  // NOLINT
       << endl;
  cout << "sizeof(unsigned long long int) = "
       << sizeof(unsigned long long int)  // NOLINT
       << endl;
  cout << "sizeof(char) = " << sizeof(char) << endl;
  cout << "sizeof(signed char) = " << sizeof(signed char) << endl;
  cout << "sizeof(unsigned char) = " << sizeof(unsigned char) << endl;
  cout << "sizeof(wchar_t) = " << sizeof(wchar_t) << endl;
  cout << "sizeof(char16_t) = " << sizeof(char16_t) << endl;
  cout << "sizeof(char32_t) = " << sizeof(char32_t) << endl;
  cout << "sizeof(float) = " << sizeof(float) << endl;
  cout << "sizeof(double) = " << sizeof(double) << endl;
  cout << "sizeof(long double) = " << sizeof(long double) << endl;

  return 0;
}
