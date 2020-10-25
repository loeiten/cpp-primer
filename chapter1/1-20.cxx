#include <iostream>

#include "Sales_item.hxx"

int main() {
  Sales_item sales_in;
  std::cout
      << "Write ISBN, number of copies sold, and sales price (EOF to exit):"
      << std::endl;
  while (std::cin >> sales_in) {
    std::cout << sales_in << std::endl;
    std::cout
        << "Write ISBN, number of copies sold, and sales price (EOF to exit):"
        << std::endl;
  }
  std::cout << "EOF caused exit." << std::endl;
}
