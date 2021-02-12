#include <iostream>
using std::cout;
using std::endl;

class Y;  // Need to declare Y as it's used in X

class X {
 public:
  X() = default;
  explicit X(Y* myY) : y(myY) {}  // NOTE: Must use pointers

  const char c = 'x';
  const Y* y = 0;  // NOTE: Must use pointers
};

class Y {
 public:
  Y() = default;
  explicit Y(X* myX) : x(myX) {}  // NOTE: Must use pointers

  const char c = 'y';
  const X* x = 0;  // NOTE: Must use pointers
};

int main() {
  X mainX;
  Y mainY(&mainX);
  X secondX(&mainY);

  cout << "mainX: char=" << mainX.c << "  pointer=" << mainX.y << endl;
  cout << "mainY: char=" << mainY.c << "  pointer=" << mainY.x << endl;
  cout << "secondX: char=" << secondX.c << "  pointer=" << secondX.y << endl;
  return 0;
}
