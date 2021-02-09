#include <iostream>
using std::cout;
using std::istream;
using std::ostream;

#include "person_7-9.hxx"

istream& Person::read(istream& is) {
  cout << "Please enter the name: ";
  getline(is, name);
  cout << "Please enter the adress: ";
  getline(is, address);
  return is;
}

ostream& Person::print(ostream& os) const {
  os << name << "\t" << address;
  return os;
}
