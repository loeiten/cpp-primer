#include "factorial.hxx"

int factorial(int number) {
  int result = 1;
  while (number > 1) {
    result *= number--;
  }
  return result;
}
