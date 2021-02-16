#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

string* reaplaceString(string* s, const string& oldVal, const string& newVal) {
  string::size_type pos = 0;
  auto oldSize = oldVal.size();
  while ((pos = s->find(oldVal, pos)) != string::npos) {
    s->replace(pos, oldSize, newVal);
    ++pos;
  }
  return s;
}

int main() {
  string myString = "\"Replace tho with though and thru by through\"";
  cout << "Original string" << endl;
  cout << myString << endl;

  reaplaceString(&myString, "tho ", "though ");
  cout << "\nAfter calling replaceString(myString, \"tho \", \"though \")"
       << endl;
  cout << myString << endl;

  reaplaceString(&myString, "thru ", "through ");
  cout << "\nAfter calling replaceString(myString, \"thru \", \"through \")"
       << endl;
  cout << myString << endl;

  reaplaceString(&myString, "foo", "bar");
  cout << "\nAfter calling replaceString(myString, \"foo\", \"bar\")" << endl;
  cout << myString << endl;
  return 0;
}
