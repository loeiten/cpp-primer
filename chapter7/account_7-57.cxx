#include "account_7-57.hxx"

double Account::interestRate =
    initRate();  // NOTE: we must initialize the interestRate in order not to
                 // raise "Undefined symbol"
void Account::setRate(double newRate) { interestRate = newRate; }
