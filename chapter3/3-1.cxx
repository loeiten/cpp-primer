#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
  int i = 50, sum = 0;
  while (i <= 100) {
    sum += i;
    ++i;
  }
  cout << sum << endl;

  i = 10;
  while (i >= 0) {
    cout << i << endl;
    --i;
  }

  int v1, v2;
  cout << "Write two numbers in descending order" << endl;
  cin >> v1 >> v2;
  while (v1 >= v2) {
    std::cout << v2 << std::endl;
    ++v2;
  }
}
