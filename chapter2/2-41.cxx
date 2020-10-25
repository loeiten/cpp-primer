#include <iostream>
#include <string>

struct SalesData {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

int main() {
  SalesData replace;
  double price;
  std::cout << "Enter book number, units sold and unit price" << std::endl;
  while (std::cin >> replace.bookNo >> replace.units_sold >> price) {
    if (replace.bookNo == "next") {
      break;
    }
    replace.revenue = replace.units_sold * price;
    std::cout << "You entered bookNo " << replace.bookNo << ",  units sold "
              << replace.units_sold << ", and revenue " << replace.revenue << ""
              << std::endl;
    std::cout << "Enter book number, units sold and unit price (exit with "
                 "bookNo 'next')"
              << std::endl;
  }

  SalesData data1, data2;
  bool the_same_book_number = false;

  while (!(the_same_book_number)) {
    std::cout << "Enter book 1:\nBook number, units sold and unit price"
              << std::endl;
    std::cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;

    std::cout << "Enter book 2:\nBook number, units sold and unit price"
              << std::endl;
    std::cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;

    if (data1.bookNo == data2.bookNo) {
      the_same_book_number = true;
      unsigned int total_numbers_sold = data1.units_sold + data2.units_sold;
      double total_revenue = data1.revenue + data2.revenue;
      double avg_revenue = total_revenue / total_numbers_sold;
      std::cout << data1.bookNo << " " << total_numbers_sold << " "
                << avg_revenue << std::endl;
    } else {
      std::cout << "data1.bookNo != data2.bookNo " << std::endl;
    }
  }

  SalesData sales_in, sales_sum;
  std::cout << "Enter book number, units sold and unit price (EOF to exit):"
            << std::endl;
  while (std::cin >> sales_in.bookNo >> sales_in.units_sold >> price) {
    sales_in.revenue = sales_in.units_sold * price;
    // Notice, due to laziness we don't check that bookNo is constant
    sales_sum.bookNo = sales_in.bookNo;
    sales_sum.units_sold += sales_in.units_sold;
    sales_sum.revenue += sales_in.revenue;
  }
  std::cout << "EOF caused exit." << std::endl;
  double avg_revenue = sales_sum.revenue / sales_sum.units_sold;
  std::cout << "Sum: " << sales_sum.bookNo << " " << sales_sum.units_sold << " "
            << avg_revenue << std::endl;

  return 0;
}
