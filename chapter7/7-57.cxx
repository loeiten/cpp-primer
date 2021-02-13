#include <iostream>
using std::cout;
using std::endl;

#include "account_7-57.hxx"

/*
Compile

clang++ -std=c++14 -Wall -Wextra -Werror -Wshadow -Wdouble-promotion -Wformat=2
-Wundef -Wconversion -g3 -Os 7-57.cxx account_7-57.cxx -o 7-57 && ./7-57
*/
int main() {
  cout << "The global rate is: " << Account::getRate() << endl;
  Account saving{"Mr Anderson", 1000.0};
  Account salary{"Mr Anderson", 100.0};

  cout << "Rate is changing to 0.01" << endl;
  saving.setRate(0.01);
  cout << "The global rate is: " << salary.getRate() << endl;

  saving.calculate();
  cout << "After one month the saving account reads: " << saving.balance()
       << endl;

  salary.calculate();
  salary.calculate();
  cout << "After two months the salary account reads: " << salary.balance()
       << endl;

  return 0;
}
