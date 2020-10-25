#include <iostream>

#include "Sales_item.hxx"

int main() {
  int sum = 1;
  Sales_item sales_old, sales_new;
  std::cout << "Write the first ISBN, number of copies sold, and sales price:"
            << std::endl;
  std::cin >> sales_old;
  std::cout << "Write the second ISBN, number of copies sold, and sales price:"
            << std::endl;
  while (std::cin >> sales_new) {
    if (sales_new.isbn() != sales_old.isbn()) {
      std::cout << "\n\n\nFinal sum for " << sales_old.isbn() << ": " << sum
                << "\n\n\n"
                << std::endl;
      sum = 1;
    } else {
      sum++;
      std::cout << "Current sum for " << sales_old.isbn() << ": " << sum << "\n"
                << std::endl;
    }
    sales_old = sales_new;
    std::cout << "Write a new ISBN, number of copies sold, and sales price "
                 "(EOF to exit):"
              << std::endl;
  }
  std::cout << "EOF caused exit." << std::endl;
  std::cout << "\n\n\nFinal sum for " << sales_old.isbn() << ": " << sum
            << std::endl;
}
