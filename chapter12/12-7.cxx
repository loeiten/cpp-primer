#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <memory>
using std::make_shared;
using std::shared_ptr;

shared_ptr<vector<int>> makeVector() { return make_shared<vector<int>>(); }

shared_ptr<vector<int>> fillVector(shared_ptr<vector<int>> v) {
  int i;
  string msg = "Please enter a number:";
  cout << msg << endl;
  while (cin >> i) {
    v->push_back(i);
    cout << msg << endl;
  }
  return v;
}

void printVector(shared_ptr<vector<int>> v) {
  cout << "\nThe numbers:" << endl;
  for (const auto el : *v) {
    cout << el << endl;
  }
}

int main() {
  auto v = makeVector();
  v = fillVector(v);
  printVector(v);

  return 0;
}
