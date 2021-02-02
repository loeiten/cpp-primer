#include <iostream>
using std::cout;
using std::endl;

#include <cstring>
using std::strcat;
using std::strcpy;
using std::strlen;

#include <iterator>
using std::begin;
using std::end;

#include <cstdint>
using std::size_t;

int main() {
  const char ca1[] = "hello";
  const char ca2[] = "world!";
  cout << "strlen(ca1)=" << strlen(ca1) << endl;
  cout << "strlen(ca2)=" << strlen(ca2) << endl;
  cout << "strlen(ca1) + strlen(ca2)=" << strlen(ca1) + strlen(ca2) << endl;
  constexpr size_t kSa = (end(ca1) - begin(ca1)) + (end(ca2) - begin(ca2));
  cout << "(end(ca1) - begin(ca1)) + (end(ca2) - begin(ca2))="
       << (end(ca1) - begin(ca1)) + (end(ca2) - begin(ca2)) << endl;
  cout << "NOTE: We have counted the NUL character twice. However, we will "
          "just use one NUL character in c3"
       << endl;
  char ca3[kSa];

  // NOTE: Assignment asks to use strcpy and strcat
  strcpy(ca3, ca1);  // NOLINT
  strcat(ca3, " ");  // NOLINT
  strcat(ca3, ca2);  // NOLINT

  cout << "strlen(ca3)=" << strlen(ca3) << endl;

  cout << ca3 << endl;

  return 0;
}
