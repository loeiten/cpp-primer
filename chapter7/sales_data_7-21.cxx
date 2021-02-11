#include <iostream>
using std::istream;
using std::ostream;

#include <exception>
using std::invalid_argument;

#include "sales_data_7-21.hxx"

SalesData::SalesData(istream& is) {
  if (!read(is, *this)) {
    throw invalid_argument("No data?!");
  }
}

SalesData& SalesData::combine(const SalesData& rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

double SalesData::avg_prince() const {
  if (units_sold) {
    return revenue / units_sold;
  } else {
    return 0;
  }
}

SalesData add(const SalesData& lhs, const SalesData& rhs) {
  SalesData sum = lhs;
  sum.combine(rhs);
  return sum;
}

// NOTE: Some argues that pointers makes it clearer to the user that the object
// can be mutated. However, references doesn't need to be copied. It's just an
// alias
istream& read(istream& is, SalesData& item) {  // NOLINT
  double pricePerBook = 0.0;
  is >> item.bookNo >> item.units_sold >> pricePerBook;
  item.revenue = pricePerBook * item.units_sold;
  return is;
}

ostream& print(ostream& os, const SalesData& item) {
  os << item.isbn() << "\t" << item.units_sold << "\t" << item.revenue << "\t"
     << item.avg_prince();
  return os;
}
