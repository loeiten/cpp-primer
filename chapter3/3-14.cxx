#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::vector;

int main() {
  vector<int> v1;
  int i;
  cout << "Enter an integer: " << endl;
  while (cin >> i) {
    v1.push_back(i);
    cout << "Enter an integer: " << endl;
  }
  cout << "v1 containing " << v1.size() << " elements, reading" << endl;

  for (auto &r : v1) {
    cout << r << endl;
  }
  return 0;
}
