#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

#include "sales_data_7-7.hxx"

/*
Compile

clang++ -std=c++14 -Wall -Wextra -Werror -Wshadow -Wdouble-promotion -Wformat=2
-Wundef -Wconversion -g3 -Os 7-7.cxx sales_data_7-7.cxx -o 7-7 && ./7-7
*/
int main() {
  SalesData total;  // variable to hold data for the next transaction
  // read the first transaction and ensure that there are data to process
  cout << "Enter book-number, units sold and price per book" << endl;
  if (read(cin, total)) {
    SalesData trans;  // variable to hold the running sum
    cout << "\nBook-number\tUnits sold\tTotal revenue\tAverage price" << endl;
    print(cout, total) << "\n" << endl;
    // read and process the remaining transactions
    cout << "Enter book-number, units sold and price per book" << endl;
    while (read(cin, trans)) {
      // if we're still processing the same book
      if (total.isbn() == trans.isbn()) {
        total = add(total, trans);  // update units sold
      } else {
        // print results for the previous book
        cout << "\nYou entered a new book number: " << trans.bookNo << endl;
        cout << "Book-number\tUnits sold\tTotal revenue\tAverage price" << endl;
        print(cout, total) << "\n" << endl;
        total = trans;  // total now refers to the next book
      }
      cout << "Enter book-number, units sold and price per book" << endl;
    }
    cout << "\nDone processing" << endl;
    cout << "Book-number\tUnits sold\tTotal revenue\tAverage price" << endl;
    print(cout, total) << "\n" << endl;
  } else {
    // no input! warn the user
    cerr << "No data?!" << endl;
    return -1;  // indicate failure
  }
  return 0;
}
