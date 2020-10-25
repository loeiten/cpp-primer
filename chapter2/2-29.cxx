#include <iostream>

int main() {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused"
  int i, *const cp = &i;
  int *p1, *const p2 = &i;
  const int ic = 42, &r = ic;
  const int *const p3 = &ic;
  const int *p = &ic;
  i = ic;
// p1 = p3;  // Will set p3 to a const address...not allowed
// p1 = &ic;  // Set the address to a const address...not allowed
// p2 = p1;  // p2 is const and connot be reset
// ic = *p3;  // ic is const
#pragma clang diagnostic pop
  return 0;
}
