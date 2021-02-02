#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::strcpy;

int main() {
  // Unsigned integer overflow
  unsigned int a = 1;
  cout << -a << endl;

  // Stack buffer overflow
  char str[1];
  strcpy(str, "Hello");  // NOLINT
  cout << str << endl;

  // short overflow
  int16_t short_value = 32767;
  short_value += 1;
  cout << short_value << endl;
  return 0;
}
