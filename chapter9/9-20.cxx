#include <iostream>
using std::cout;
using std::endl;

#include <deque>
using std::deque;

#include <list>
using std::list;

void print(const deque<int>& d) {
  for (auto const& el : d) {
    cout << el << endl;
  }
}

int main() {
  list<int> li;
  deque<int> even;
  deque<int> odd;

  for (int i = 0; i <= 9; ++i) {
    li.push_back(i);
  }

  for (auto el : li) {
    if (el % 2 == 0) {
      even.push_back(el);
    } else {
      odd.push_back(el);
    }
  }

  cout << "Printing even: " << endl;
  print(even);

  cout << "Printing odd: " << endl;
  print(odd);
  return 0;
}
