#ifndef CHAPTER7_SALES_DATA_7_7_HXX_
#define CHAPTER7_SALES_DATA_7_7_HXX_

#include <iostream>
using std::istream;
using std::ostream;

#include <string>
using std::string;

struct SalesData {
  string isbn() const { return bookNo; }
  SalesData& combine(const SalesData&);
  double avg_prince() const;

  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

SalesData add(const SalesData& lhs, const SalesData& rhs);
// NOTE: Some argues that pointers makes it clearer to the user that the object
// can be mutated. However, references doesn't need to be copied. It's just an
// alias
istream& read(istream& is, SalesData& item);  // NOLINT
ostream& print(ostream& os, const SalesData& item);

#endif  // CHAPTER7_SALES_DATA_7_7_HXX_
