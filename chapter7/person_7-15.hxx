#ifndef CHAPTER7_PERSON_7_15_HXX_
#define CHAPTER7_PERSON_7_15_HXX_

#include <iostream>
using std::istream;
using std::ostream;

#include <string>
using std::string;

struct Person {
  Person() = default;
  Person(const string& n, const string& a) : name(n), address(a) {}
  explicit Person(istream&);

  string name;
  string address;

  string getName() const { return name; }
  string getAddress() const { return address; }
  // NOTE: Maybe pointer would be better in order to make it obvious that p is
  // non-const
  istream& read(istream& is, Person& p);  // NOLINT
  ostream& print(ostream& os) const;
};

#endif  // CHAPTER7_PERSON_7_15_HXX_
