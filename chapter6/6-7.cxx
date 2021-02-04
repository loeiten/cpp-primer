#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int count_calls() {
  static int count = -1;
  return ++count;
}

int main() {
  int max;
  cout << "Number of calls:" << endl;
  cin >> max;
  for (int i = 0; i < max; ++i) {
    cout << "Call number " << count_calls() << endl;
  }
  return 0;
}
