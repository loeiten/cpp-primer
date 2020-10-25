#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

int main() {
  vector<int> v1(10, 42);
  vector<int> v2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
  vector<int> v3 = v2;
  cout << "v1 size " << v1.size() << endl;
  cout << "v2 size " << v2.size() << endl;
  cout << "v3 size " << v3.size() << endl;
  return 0;
}
