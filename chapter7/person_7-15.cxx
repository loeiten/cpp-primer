#include <iostream>
using std::cout;
using std::istream;
using std::ostream;

#include <exception>
using std::invalid_argument;

#include "person_7-15.hxx"

Person::Person(istream& is) {
  if (!read(is, *this)) {
    throw invalid_argument("No data?!");
  }
}

istream& Person::read(istream& is, Person& p) {
  cout << "Please enter the name: ";
  getline(is, p.name);
  cout << "Please enter the adress: ";
  getline(is, p.address);
  return is;
}

ostream& Person::print(ostream& os) const {
  os << name << "\t" << address;
  return os;
}
