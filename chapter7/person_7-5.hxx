#ifndef CHAPTER7_PERSON_7_5_HXX_
#define CHAPTER7_PERSON_7_5_HXX_

#include <string>
using std::string;

struct Person {
  string name;
  string address;

  string getName() const { return name; }
  string getAddress() const { return address; }
};

#endif  // CHAPTER7_PERSON_7_5_HXX_
