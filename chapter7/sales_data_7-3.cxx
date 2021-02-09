#include "sales_data_7-3.hxx"

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
