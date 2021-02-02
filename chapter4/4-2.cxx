#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

int main() {
  vector<int> v(2);
  v[0] = 7;
  v[1] = 3;
  for (auto i : v) {
    cout << i << endl;
  }
  cout << *v.begin() << endl;
  cout << *(v.begin()) << endl;

  cout << *v.begin() + 1 << endl;
  cout << (*(v.begin())) + 1 << endl;
  return 0;
}
