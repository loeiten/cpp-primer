#include <valgrind/callgrind.h>

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void print(const string& s) { cout << s << endl; }

int main() {
  CALLGRIND_START_INSTRUMENTATION;  // Together with --instr-atstart=no
  CALLGRIND_TOGGLE_COLLECT;         // Together with --collect-atstart=no
  cout << "Hello, world!" << endl;
  print("One");
  print("Two");
  print("Three");
  CALLGRIND_TOGGLE_COLLECT;
  CALLGRIND_STOP_INSTRUMENTATION;
  return 0;
}
