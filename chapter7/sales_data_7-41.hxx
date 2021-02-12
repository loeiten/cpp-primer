#ifndef CHAPTER7_SALES_DATA_7_41_HXX_
#define CHAPTER7_SALES_DATA_7_41_HXX_

#include <iostream>
using std::istream;
using std::ostream;

#include <string>
using std::string;

#include <exception>
using std::invalid_argument;

class SalesData {
  friend SalesData add(const SalesData& lhs, const SalesData& rhs);
  // NOTE: Some argues that pointers makes it clearer to the user that the
  // object can be mutated. However, references doesn't need to be copied. It's
  // just an alias
  friend istream& read(istream& is, SalesData& item);  // NOLINT
  friend ostream& print(ostream& os, const SalesData& item);

 public:
  SalesData(const string& s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(n * p) {}
  SalesData() : SalesData("", 0, 0) {}
  explicit SalesData(const string& s) : SalesData(s, 0, 0) {}
  explicit SalesData(istream& is) : SalesData() {
    if (!read(is, *this)) {
      throw invalid_argument("No data?!");
    }
  }

  string isbn() const { return bookNo; }
  SalesData& combine(const SalesData&);

 private:
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

#endif  // CHAPTER7_SALES_DATA_7_41_HXX_
