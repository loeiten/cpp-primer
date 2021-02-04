#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;

#include <string>
using std::string;

#include <sstream>
using std::istringstream;

#include <vector>
using std::vector;

void print_v(vector<int>* v) {
  for (auto const& el : *v) {
    cout << el << endl;
  }
}

int main() {
  int i;
  bool isPrefix = false;
  string isitring;
  istringstream iss;
  vector<int> va, vb, prefix;

  cout << "Enter elements of vector a (separated by space):" << endl;
  getline(cin, isitring);
  iss.str(isitring);
  while (iss >> i) {
    va.push_back(i);
  }
  cout << "You entered" << endl;
  print_v(&va);

  cout << "Enter elements of vector b (separated by space):" << endl;
  getline(cin, isitring);
  iss.clear();
  iss.str(isitring);
  while (iss >> i) {
    vb.push_back(i);
  }
  cout << "You entered" << endl;
  print_v(&vb);

  for (auto ita = va.begin(), itb = vb.begin();
       ita != va.end() && itb != vb.end(); ++ita, ++itb) {
    if (*ita == *itb) {
      isPrefix = true;
      prefix.push_back(*ita);
    } else {
      break;
    }
  }

  if (isPrefix) {
    cout << "Prefix found: " << endl;
    print_v(&prefix);
  } else {
    cout << "No prefix found" << endl;
  }
  return 0;
}
