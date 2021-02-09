#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>

#include "person_7-5.hxx"
using std::getline;

int main() {
  Person p1;
  cout << "Name: ";
  getline(cin, p1.name);
  cout << "Address: ";
  getline(cin, p1.address);

  cout << p1.name << "lives at " << p1.address << endl;
  return 0;
}
