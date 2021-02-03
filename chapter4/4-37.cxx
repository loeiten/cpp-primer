#include <string>
using std::string;

int main() {
  int i;
  double d;
  const string* ps;
  char dummy = 'a';
  char* pc = &dummy;
  void* pv;

  pv = static_cast<void*>(&ps);
  i = static_cast<int>(*pc);
  pv = static_cast<void*>(&d);
  pc = static_cast<char*>(pv);

  return 0;
}
