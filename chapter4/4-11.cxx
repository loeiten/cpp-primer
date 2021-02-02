#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
  int a, b, c, d;
  cout << "Enter 'a' (should be greater than b)" << endl;
  cin >> a;
  cout << "Enter 'b' (should be greater than c)" << endl;
  cin >> b;
  cout << "Enter 'c' (should be greater than d)" << endl;
  cin >> c;
  cout << "Enter 'd'" << endl;
  cin >> d;
  if (b > a) {
    cout << "b>a...you lose" << endl;
  } else if (c > b) {
    cout << "c>b...you lose" << endl;
  } else if (d > c) {
    cout << "c>d...you lose" << endl;
  } else {
    cout << "You win...kiwaii" << endl;
  }
  return 0;
}
