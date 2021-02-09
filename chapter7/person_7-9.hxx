#ifndef CHAPTER7_PERSON_7_9_HXX_
#define CHAPTER7_PERSON_7_9_HXX_

#include <iostream>
using std::istream;
using std::ostream;

#include <string>
using std::string;

struct Person {
  string name;
  string address;

  string getName() const { return name; }
  string getAddress() const { return address; }
  istream& read(istream& is);
  ostream& print(ostream& os) const;
};

#endif  // CHAPTER7_PERSON_7_9_HXX_
