#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// Bucketizing into tens
// Input: 42 65 95 100 39 67 95 76 88 76 83 92 76 93
// Should return: 0 0 0 1 1 0 2 3 2 4 1
int main() {
  vector<unsigned> scores(11, 0);
  auto beg = scores.begin();
  unsigned int grade;
  cout << "Enter a grade:" << endl;
  while (cin >> grade) {
    if (grade <= 100) {
      // ++score[grade / 10];
      ++*(beg + grade / 10);
    }
    cout << "Enter a grade:" << endl;
  }
  for (auto it = scores.begin(); it != scores.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
  return 0;
}
