#include <iostream>
using std::cout;
using std::endl;

int main() {
  float expr = -30 * 3 + 21 / 5;
  float ans = -86;
  bool is_true = expr == ans;
  cout << "-30*3 + 21/5"
       << "=" << expr << "=" << ans << " is " << is_true << endl;

  expr = -30 + 3 * 21 / 5;
  ans = -18;
  is_true = expr == ans;
  cout << "-30 +3*21/5"
       << "=" << expr << "=" << ans << " is " << is_true << endl;

  expr = 30 / 3 * 21 % 5;
  ans = 0;
  is_true = expr == ans;
  cout << "30/3*21%5"
       << "=" << expr << "=" << ans << " is " << is_true << endl;

  expr = -30 / 3 * 21 % 4;
  ans = -2;
  is_true = expr == ans;
  cout << "-30/3*21%4"
       << "=" << expr << "=" << ans << " is " << is_true << endl;

  return 0;
}
