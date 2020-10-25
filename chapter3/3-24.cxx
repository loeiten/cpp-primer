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

  // Begin on +1 since we are subtracting one
  for (auto it = v.cbegin() + 1; it != v.cend(); ++it) {
    cout << *(it - 1) << " + " << *it << " = " << *(it - 1) + *it << endl;
  }
  cout << endl;
  // From table 3.7 (Operations Supported by vector and string Iterators)

  // First we use iter1 - iter2 which returns a NUMBER
  // (v.cend() - it) <-- returns a NUMBER so that it + (v.cend() - it) gives
  // v.cend()

  // Next we use number - n which also returns as NUMBER
  // (v.cend() - it) - 1 <-- returns a NUMBER
  // We subtract by one as v.cend() points at one after the end of the container
  // Thus, we could have done v[(v.cend() - it) - 1]
  // But not all containers have implemented subscripting

  // Finally we use iter + n which returens an ITERATOR
  for (auto it = v.cbegin(); it != v.cend(); ++it) {
    cout << *it << " + " << *(v.begin() + (v.cend() - it) - 1) << " = "
         << *it + *(v.begin() + (v.cend() - it) - 1) << endl;
  }
  return 0;
}
