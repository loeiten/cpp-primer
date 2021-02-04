#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
  cout << "Got " << argc << " parameters" << endl;
  for (int i = 0; i < argc; ++i) {
    cout << argv[i] << endl;
  }
  return 0;
}
