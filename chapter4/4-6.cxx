#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

int main() {
  string even_odd[]{"even", "odd"};
  for (int i = 0; i <= 100; ++i) {
    cout << i << " is " << even_odd[i % 2] << endl;
  }
  return 0;
}
