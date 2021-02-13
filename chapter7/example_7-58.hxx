#ifndef CHAPTER7_EXAMPLE_7_58_HXX_
#define CHAPTER7_EXAMPLE_7_58_HXX_

#include <vector>
using std::vector;

class Example {
 public:
  static constexpr double rate = 6.5;
  static constexpr int vecSize = 20;
  // 1. cannot use parentheses as in-class initializer
  static vector<double> vec;  // (vecSize)
};

#endif  // CHAPTER7_EXAMPLE_7_58_HXX_
