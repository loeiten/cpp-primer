#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

int main() {
  vector<int> v;
  int i;
  cout << "Give me an integer: " << endl;
  while (cin >> i) {
    v.push_back(i);
    cout << "Give me an integer: " << endl;
  }

  cout << "v.size() " << v.size() << endl;

  // NOTE: We begin at s=1 as we are subtracting from the index
  for (decltype(v.size()) s = 1; s < v.size(); ++s) {
    cout << "Sum of index " << s - 1 << " and index " << s << " = "
         << v[s - 1] + v[s] << endl;
  }
  cout << endl;
  // NOTE: We begin at s=0 and index v.size() - (s+1) as v.size() - 1 is the
  // last element
  for (decltype(v.size()) s = 0; s < v.size(); ++s) {
    cout << "Sum of index " << s << " and index " << v.size() - (s + 1) << " = "
         << v[s] + v[v.size() - (s + 1)] << endl;
  }
  return 0;
}
