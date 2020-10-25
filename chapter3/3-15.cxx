#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::vector;

using std::string;

int main() {
  vector<string> v1;
  string s;
  cout << "Enter a string: " << endl;
  while (cin >> s) {
    v1.push_back(s);
    cout << "Enter a string: " << endl;
  }
  cout << "v1 containing " << v1.size() << " elements, reading" << endl;

  for (auto &r : v1) {
    cout << r << endl;
  }
  return 0;
}
