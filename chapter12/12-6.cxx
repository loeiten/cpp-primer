#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

vector<int>* makeVector() { return new vector<int>; }

vector<int>* fillVector(vector<int>* v) {
  int i;
  string msg = "Please enter a number:";
  cout << msg << endl;
  while (cin >> i) {
    v->push_back(i);
    cout << msg << endl;
  }
  return v;
}

void printVector(vector<int>* v) {
  cout << "\nThe numbers:" << endl;
  for (const auto el : *v) {
    cout << el << endl;
  }
}

int main() {
  auto v = makeVector();
  v = fillVector(v);
  printVector(v);

  delete v;
  return 0;
}
