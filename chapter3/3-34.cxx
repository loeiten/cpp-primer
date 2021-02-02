#include <iostream>
using std::cout;
using std::endl;

int main() {
  int ia[] = {1, 2, 3};
  int *p1 = &ia[1];
  int *p2 = &ia[2];
  cout << "p2 is pointing at ia[2]\np1 is pointing at ia[1]\np2-p1=1, so "
          "p1+(p2-p1)=p2"
       << endl;
  p1 += p2 - p1;
  cout << "*p1=" << *p1 << endl;
  cout << "Doing the same again, we get p1+(p2-p1)=p2" << endl;
  p1 += p2 - p1;
  cout << "*p1=" << *p1 << endl;
  cout << "Let p1 point to the first element" << endl;
  p1 = &ia[0];
  cout << "We still get p1+(p2-p1)=p2" << endl;
  p1 += p2 - p1;
  cout << "*p1=" << *p1 << endl;
  return 0;
}
