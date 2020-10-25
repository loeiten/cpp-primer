#include <iostream>

#include "Sales_item.hxx"

int main() {
  Sales_item item1, item2;
  std::cout
      << "Write 2  sales items (ISBN, number of copies sold, and sales price):"
      << std::endl;
  std::cin >> item1 >> item2;
  std::cout << "Sum:" << item1 + item2 << std::endl;
}
