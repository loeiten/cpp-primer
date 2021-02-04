#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

string my_string[10] = {"a", "b", "c", "d", "e",  // NOLINT
                        "f", "g", "h", "i", "j"};

string (&get_strings())[10] { return my_string; }

int main() {
  string(&main_string)[10] = get_strings();
  main_string[2] = "hahaha";
  for (auto const &el : my_string) {
    cout << el << endl;
  }
  return 0;
}
