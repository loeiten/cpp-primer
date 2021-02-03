#include <iostream>
using std::cout;
using std::endl;

#include <bitset>
using std::bitset;

int main() {
  unsigned char c = 'q';
  bitset<8> q(c);
  cout << q << endl;
  cout << (q << 6) << endl;
  // Note ~ has highest precedence
  cout << (~q << 6) << endl;
  return 0;
}
