#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <sstream>
using std::stringstream;

#include <string>
using std::string;

#include <cctype>
using std::ispunct;

#include <algorithm>
using std::remove_if;
using std::sort;
using std::stable_sort;
using std::unique;

#include <vector>
using std::vector;

void print(const vector<string>& v) {
  for (const auto& el : v) {
    cout << el << endl;
  }
}

bool isShorter(const string& s1, const string& s2) {
  return s1.size() < s2.size();
}

void elimDups(vector<string>* v) {
  sort(v->begin(), v->end());
  auto end = unique(v->begin(), v->end());
  v->erase(end, v->end());
}

int main() {
  string s = "a long, long time ago in a galaxy far, far away.";
  string tmp;
  vector<string> vec;

  cout << "Original string" << endl;
  cout << s << endl;
  // Remove any punctuation
  // https://stackoverflow.com/questions/19138983/c-remove-punctuation-from-string
  // Apparantly one can use ::ispunct to take care of the overload problem
  auto it = remove_if(s.begin(), s.end(),
                      [](const char& c) -> bool { return ispunct(c); });
  s.erase(it, s.end());
  cout << "\nString without punctuation" << endl;
  cout << s << endl;

  // Split the string at the place of spaces
  stringstream ss(s);
  while (ss >> tmp) {
    vec.push_back(tmp);
  }

  cout << "Original vector" << endl;
  print(vec);

  elimDups(&vec);
  cout << "\nAfter eliminating" << endl;
  print(vec);

  stable_sort(vec.begin(), vec.end(), isShorter);
  cout << "\nAfter stable sorting" << endl;
  print(vec);
  return 0;
}
