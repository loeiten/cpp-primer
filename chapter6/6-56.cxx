#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

inline int add(const int &a, const int &b) { return a + b; }
inline int subtract(const int &a, const int &b) { return a - b; }
inline int multiply(const int &a, const int &b) { return a * b; }
inline int divide(const int &a, const int &b) { return a / b; }

int main() {
  vector<int (*)(const int &, const int &)> vf;
  int i = 4, i2 = 2;
  vf.push_back(&add);
  vf.push_back(&subtract);
  vf.push_back(&multiply);
  vf.push_back(&divide);

  for (auto &f : vf) {
    cout << f(i, i2) << endl;
  }
  return 0;
}
