#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
  vector<int> v;
  vector<int> vd;
  for (int i = 0; i <= 10; ++i) {
    v.push_back(i);
  }
  for (auto it = v.cbegin(); it != v.cend(); ++it) {
    vd.push_back(2 * *it);
  }
  cout << "Doubles of the first 10 numbers" << endl;
  for (auto it = vd.cbegin(); it != vd.cend(); ++it) {
    cout << *it << endl;
  }
  return 0;
}
