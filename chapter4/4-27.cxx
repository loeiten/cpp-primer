#include <iostream>
using std::cout;
using std::endl;

#include <bitset>
using std::bitset;

int main() {
  unsigned long uli1 = 3, uli2 = 7;  // NOLINT
  bitset<32> ul1(uli1);
  bitset<32> ul2(uli2);
  cout << ul1 << endl;
  cout << ul2 << endl;

  cout << "\n" << endl;
  cout << (ul1 & ul2) << endl;
  cout << (ul1 | ul2) << endl;

  cout << "\n" << endl;
  cout << (uli1 && uli2) << endl;
  cout << (uli1 || uli2) << endl;
  return 0;
}
