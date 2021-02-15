#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

vector<int>::iterator find(const vector<int>::iterator& begin,
                           const vector<int>::iterator& end,
                           const int& findValue) {
  for (auto s = begin; s != end; ++s) {
    if (*s == findValue) {
      return s;
    }
  }
  return end;
}

int main() {
  vector<int> even{0, 2, 4, 6, 8};
  int findValue = 0;
  if (find(even.begin(), even.end(), findValue) != even.end()) {
    cout << findValue << " found in vector" << endl;
  }
  findValue = 8;
  if (find(even.begin(), even.end(), findValue) != even.end()) {
    cout << findValue << " found in vector" << endl;
  }
  findValue = 1;
  if (find(even.begin(), even.end(), findValue) == even.end()) {
    cout << findValue << " NOT found in vector" << endl;
  }
  return 0;
}
