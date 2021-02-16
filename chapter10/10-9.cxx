#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <algorithm>
using std::sort;
using std::unique;

#include <vector>
using std::vector;

void print(const vector<int>& v) {
  for (const auto el : v) {
    cout << el << endl;
  }
}

void elimDups(vector<int>* v) {
  sort(v->begin(), v->end());
  auto end = unique(v->begin(), v->end());
  v->erase(end, v->end());
}

int main() {
  vector<int> vec{10, 2, 2, 8, 2, 8, 5};

  cout << "Original vector" << endl;
  print(vec);

  elimDups(&vec);
  cout << "After eliminating" << endl;
  print(vec);
  return 0;
}
