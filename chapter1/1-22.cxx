#include <iostream>

#include "Sales_item.hxx"

int main() {
  Sales_item sales_sum, sales_in;
  std::cout
      << "Write ISBN, number of copies sold, and sales price (EOF to exit):"
      << std::endl;
  while (std::cin >> sales_in) {
    sales_sum += sales_in;
  }
  std::cout << "EOF caused exit." << std::endl;
  std::cout << "Sum:" << sales_sum << std::endl;
}
