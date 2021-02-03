#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

void print_pass_or_fail_if_esle(vector<int>* vec) {
  for (auto i = vec->begin(); i != vec->end(); i++) {
    cout << *i << endl;
  }
}

int main() {
  vector<int> ivec{0, 1, 2, 3, 4, 5};

  cout << "Original vector" << endl;
  print_pass_or_fail_if_esle(&ivec);

  for (auto i = ivec.begin(); i != ivec.end(); i++) {
    // If there is a remainder in the division, the result will be non-zero
    // A non-zero is interpreted as true
    *i = *i % 2 ? *i * 2 : *i;
  }

  cout << "\nVector where odd elements are multiplied by 2" << endl;
  print_pass_or_fail_if_esle(&ivec);

  return 0;
}
