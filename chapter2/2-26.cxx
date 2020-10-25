#include <iostream>

int main() {
  // const int buf;  // Requires an initializer
  int cnt = 0;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused"
  const int sz = cnt;
#pragma clang diagnostic pop
  ++cnt;
  // ++sz;  // lvalue not modifiable
  return 0;
}
