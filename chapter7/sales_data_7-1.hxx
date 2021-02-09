#ifndef CHAPTER7_SALES_DATA_7_1_HXX_
#define CHAPTER7_SALES_DATA_7_1_HXX_
#include <string>

struct SalesData {
  std::string book_no;
  unsigned units_sold = 0;
  double price_per_book = 0.0;
  double revenue = 0.0;
};
#endif  // CHAPTER7_SALES_DATA_7_1_HXX_
