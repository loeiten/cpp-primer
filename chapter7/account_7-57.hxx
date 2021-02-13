#ifndef CHAPTER7_ACCOUNT_7_57_HXX_
#define CHAPTER7_ACCOUNT_7_57_HXX_

#include <string>
using std::string;

class Account {
 public:
  Account(const string& o, double a) : owner(o), amount(a) {}

  void calculate() { amount += amount * interestRate; }
  static double getRate() { return interestRate; }
  static void setRate(double);
  double balance() { return amount; }

 private:
  string owner;
  double amount = 0.0;
  static double interestRate;
  static double initRate() { return 0.1; }
};

#endif  // CHAPTER7_ACCOUNT_7_57_HXX_
