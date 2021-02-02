#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <cstring>
using std::strcmp;

int main() {
  const char ca1[] = {'h', 'e', 'l', 'l', 'o', '\0'};
  const char ca2[] = {'h', 'e', 'l', 'l', 'o', '\0'};
  const char ca3[] = {'h', 'e', 'l', 'l', 'a', '\0'};
  const char ca4[] = {'h', 'e', 'l', 'l', 'o', '4', '\0'};

  if (strcmp(ca1, ca2) == 0) {
    cout << "ca1 and ca2 are equal" << endl;
  }
  if (strcmp(ca1, ca3) > 0) {
    cout << "ca1 > ca3 (i.e. " << ca1 << " > " << ca3 << ")" << endl;
  }
  if (strcmp(ca1, ca4) < 0) {
    cout << "ca1 < ca4 (i.e. " << ca1 << " < " << ca4 << ")" << endl;
  }

  string s1 = "hello";
  string s2 = "hello";
  string s3 = "hella";
  string s4 = "hello4";

  if (s1 == s2) {
    cout << "s1 and s2 are equal" << endl;
  }
  if (s1 > s3) {
    cout << "s1 > s3 (i.e. " << s1 << " > " << s3 << ")" << endl;
  }
  if (s1 < s4) {
    cout << "s1 < ca4 (i.e. " << s1 << " < " << s4 << ")" << endl;
  }

  return 0;
}
