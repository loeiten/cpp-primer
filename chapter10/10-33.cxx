#include <fstream>
using std::ifstream;
using std::ofstream;

#include <istream>
using std::istream_iterator;

#include <ostream>
using std::ostream_iterator;

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

int main() {
  ifstream inFile("10-33_in.txt");
  ofstream evenFile("delme_even_10-33_in.txt");
  ofstream oddFile("delme_odd_10-33_in.txt");

  istream_iterator<int> inIter(inFile), eof;  // Empty iterator is EOF
  ostream_iterator<int> evenIter(evenFile, " ");
  ostream_iterator<int> oddIter(oddFile, "\n");

  // Entring raw to vector
  vector<int> vec(inIter, eof);
  cout << "Checking that the input vector has been read" << endl;
  for (const auto el : vec) {
    cout << el << endl;
  }

  sort(vec.begin(), vec.end());
  cout << "\nAfter sorting" << endl;
  for (const auto el : vec) {
    cout << el << endl;
  }

  for (const auto el : vec) {
    if (el % 2) {
      // NOTE: * and ++ are superfluous, but increases readability
      *oddIter++ = el;  // ++ Has precendence over *
    } else {
      *evenIter++ = el;
    }
  }
  return 0;
}
