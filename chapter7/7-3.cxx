#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

#include "sales_data_7-3.hxx"

void print(const SalesData& sd) {
  cout << "\nBook-number: " << sd.bookNo << endl;
  cout << "Units sold: " << sd.units_sold << endl;
  cout << "Total revenue: " << sd.revenue << endl;
  cout << "Average price: " << sd.avg_prince() << "\n" << endl;
}

/*
Compile

clang++ -std=c++14 -Wall -Wextra -Werror -Wshadow -Wdouble-promotion -Wformat=2
-Wundef -Wconversion -g3 -Os 7-3.cxx sales_data_7-3.cxx -o 7-3 && ./7-3
*/
int main() {
  SalesData total;  // variable to hold data for the next transaction
  // read the first transaction and ensure that there are data to process
  cout << "Enter book-number, units sold and total revenue" << endl;
  if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
    SalesData trans;  // variable to hold the running sum
    print(total);
    // read and process the remaining transactions
    cout << "Enter book-number, units sold and total revenue" << endl;
    while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
      // if we're still processing the same book
      if (total.isbn() == trans.isbn()) {
        total.combine(trans);  // update units sold
      } else {
        // print results for the previous book
        cout << "You entered a new book number: " << trans.bookNo << endl;
        print(total);
        total = trans;  // total now refers to the next book
      }
      cout << "Enter book-number, units sold and total revenue" << endl;
    }
    cout << "Done processing" << endl;
    print(total);
  } else {
    // no input! warn the user
    cerr << "No data?!" << endl;
    return -1;  // indicate failure
  }
  return 0;
}
