#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

bool find(const vector<int>::iterator& begin, const vector<int>::iterator& end,
          const int& findValue) {
  for (auto s = begin; s != end; ++s) {
    if (*s == findValue) {
      return true;
    }
  }
  return false;
}

int main() {
  vector<int> even{0, 2, 4, 6, 8};
  int findValue = 2;
  if (find(even.begin(), even.end(), findValue)) {
    cout << findValue << " found in vector" << endl;
  }
  findValue = 3;
  if (!find(even.begin(), even.end(), findValue)) {
    cout << findValue << " NOT found in vector" << endl;
  }
  return 0;
}
