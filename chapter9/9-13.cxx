#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <list>
using std::list;

void print(const vector<double>& v) {
  for (auto e : v) {
    cout << e << endl;
  }
}

int main() {
  list<int> even{0, 2, 4, 6, 8};
  vector<double> evenCopy(even.begin(), even.end());
  print(evenCopy);

  vector<int> evenTen{10, 12, 14, 16, 18};
  vector<double> evenTenCopy(evenTen.begin(), evenTen.end());
  print(evenTenCopy);
  return 0;
}
