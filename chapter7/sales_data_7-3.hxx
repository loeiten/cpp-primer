#ifndef CHAPTER7_SALES_DATA_7_3_HXX_
#define CHAPTER7_SALES_DATA_7_3_HXX_
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
#endif  // CHAPTER7_SALES_DATA_7_3_HXX_
