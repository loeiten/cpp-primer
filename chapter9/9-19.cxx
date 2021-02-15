#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::getline;
using std::string;

#include <deque>
using std::deque;

#include <list>
using std::list;

int main() {
  deque<string> ds;
  list<string> ls;
  string current_string;

  cout << "Please enter strings" << endl;
  while (getline(cin, current_string)) {
    ds.push_back(current_string);
    ls.push_back(current_string);
  }

  cout << "\nPrinting deque" << endl;
  for (deque<string>::const_iterator el = ds.cbegin(); el != ds.cend(); ++el) {
    cout << *el << endl;
  }

  cout << "\nPrinting list" << endl;
  for (list<string>::const_iterator el = ls.cbegin(); el != ls.cend(); ++el) {
    cout << *el << endl;
  }
  return 0;
}
