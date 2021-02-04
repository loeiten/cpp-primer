#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <initializer_list>
using std::initializer_list;

int sum(initializer_list<int> il) {
  int result = 0;
  for (const int& elem : il) {
    result += elem;
  }
  return result;
}

int main() {
  cout << sum({1, 2, 3, 4, 5}) << endl;
  return 0;
}
