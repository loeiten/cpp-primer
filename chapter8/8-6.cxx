#include <iostream>
using std::cerr;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <exception>
using std::invalid_argument;

#include "sales_data_8-6.hxx"

/*
Compile and run

clang++ -std=c++14 -Wall -Wextra -Werror -Wshadow -Wdouble-promotion -Wformat=2
-Wundef -Wconversion -g3 -Os 8-6.cxx sales_data_8-6.cxx -o 8-6 && ./8-6
data_8-6.txt delme.txt
*/
int main(int argc, char *argv[]) {
  ifstream input(argv[1]);
  ofstream output;
  if (argc < 3) {
    string message = "Usage: ./8-6 data_in_file data_out_file <append>";
    cerr << message << endl;
    throw invalid_argument(message);
  }

  if (argc == 4) {
    output.open(argv[2], ofstream::app);
  } else {
    output.open(argv[2]);
  }

  SalesData total;
  if (read(input, total)) {
    SalesData trans;
    while (read(input, trans)) {
      if (total.isbn() == trans.isbn()) {
        total.combine(trans);
      } else {
        print(output, total);
        total = trans;
      }
    }
    print(output, total);
  } else {
    cerr << "No data?!" << endl;
  }

  return 0;
}
