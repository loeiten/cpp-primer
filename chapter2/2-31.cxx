#include <iostream>

int main() {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused"
  const int v2 = 0;
  int v1 = v2;
  int *p1 = &v1, &r1 = v1;
  const int *p2 = &v2, *const p3 = &v1, &r2 = v2;
  r1 = v2;
  // p1 = p2;  // p2 is const int *
  p2 = p1;  // ok, only thing not allowed is to change the value through p2
  // p1 = p3;  // p3 is const int *
  p2 = p3;  // ok
#pragma clang diagnostic pop
  return 0;
}
