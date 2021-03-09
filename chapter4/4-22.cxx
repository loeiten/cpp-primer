#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

void print_pass_or_fail_if_esle(vector<int>* vec) {
  for (auto i = vec->begin(); i != vec->end(); i++) {
    cout << *i << " - ";
    if (*i < 60) {
      cout << "fail" << endl;
    } else if (*i > 90) {
      cout << "high pass" << endl;
    } else if (*i > 75) {
      cout << "pass" << endl;
    } else {
      cout << "low pass" << endl;
    }
  }
}

void print_pass_or_fail_conditional(vector<int>* vec) {
  for (auto i = vec->begin(); i != vec->end(); i++) {
    cout << *i << " - ";
    cout << ((*i < 60)
                 ? "fail"
                 : (*i <= 75) ? "low pass" : (*i <= 90) ? "pass" : "high pass")
         << endl;
  }
}

int main() {
  vector<int> grades{10, 20, 30, 40, 50, 60, 70, 75, 80, 90, 100};

  print_pass_or_fail_if_esle(&grades);
  cout << "\n" << endl;
  print_pass_or_fail_conditional(&grades);

  return 0;
}
