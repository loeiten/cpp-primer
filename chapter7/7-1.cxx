#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

#include "sales_data_7-1.hxx"

void print(const SalesData& sd) {
  cout << "Book-number: " << sd.book_no << endl;
  cout << "Units sold: " << sd.units_sold << endl;
  cout << "Price per book: " << sd.price_per_book << endl;
  cout << "Total revenue: " << sd.revenue << endl;
}

int main() {
  SalesData total;  // variable to hold data for the next transaction
  // read the first transaction and ensure that there are data to process
  cout << "Enter book-number, units sold and price per book" << endl;
  if (cin >> total.book_no >> total.units_sold >> total.price_per_book) {
    SalesData trans;  // variable to hold the running sum
    total.revenue = total.units_sold * total.price_per_book;
    print(total);
    // read and process the remaining transactions
    cout << "Enter book-number, units sold and price per book" << endl;
    while (cin >> trans.book_no >> trans.units_sold >> trans.price_per_book) {
      // if we're still processing the same book
      if (total.book_no == trans.book_no) {
        total.units_sold += trans.units_sold;  // update units sold
        total.revenue += trans.units_sold * trans.price_per_book;
      } else {
        // print results for the previous book
        cout << "You entered a new book number: " << trans.book_no << endl;
        print(total);
        total = trans;  // total now refers to the next book
        total.revenue = total.units_sold * total.price_per_book;
      }
      cout << "Enter book-number, units sold and price per book" << endl;
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
