#ifndef CHAPTER2_SALES_DATA_HXX_
#define CHAPTER2_SALES_DATA_HXX_
#include <string>

struct SalesData {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};
#endif  // CHAPTER2_SALES_DATA_HXX_
