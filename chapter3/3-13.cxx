#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;

using std::string;

using std::vector;

int main() {
  vector<int> v1;
  vector<int> v2(10);
  vector<int> v3(10, 42);
  vector<int> v4{10};
  vector<int> v5{10, 42};
  vector<string> v6{10};
  vector<string> v7{10, "hi"};
  cout << "Size of vector<int> v1 " << v1.size() << endl;
  cout << "Size of vector<int> v2(10) " << v2.size() << endl;
  cout << "Size of vector<int> v3(10, 42) " << v3.size() << endl;
  cout << "Size of vector<int> v4{10} " << v4.size() << endl;
  cout << "Size of vector<int> v5{10, 42} " << v5.size() << endl;
  cout << "Size of vector<string> v6{10} " << v6.size() << endl;
  cout << "Size of vector<string> v7{10, \"hi\"} " << v7.size() << endl;
  return 0;
}
