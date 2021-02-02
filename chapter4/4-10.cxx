#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
  int in;
  cout << "Entering 42 will end the program" << endl;
  while (cin >> in) {
    if (in == 42) {
      cout << "Program ended" << endl;
      break;
    }
  }
  return 0;
}
