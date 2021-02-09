#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

string make_plural(size_t ctr, const string& word, const string& ending = "s") {
  return (ctr > 1) ? word + ending : word;
}

int main() {
  cout << make_plural(1, "book") << endl;
  cout << make_plural(100, "book") << endl;
  cout << make_plural(1, "book", "shelves") << endl;
  cout << make_plural(15, "book", "shelves") << endl;
  return 0;
}
