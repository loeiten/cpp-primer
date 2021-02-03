#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;

#include <string>
using std::string;

/*
Testcase:
This test used far more time than it should.
I incorporated the tab  , the space and the newline
Additionally, I added count of uppercase
I'm able to run this test now...finally
That's flawless ffs

Yields
Number of a = 14
Number of e = 17
Number of i = 12
Number of o = 9
Number of u = 5
Number of vowels = 57

Number of spaces = 31
Number of tabs = 0 (note that these are converted to spaces)
Number of newlines = 5

Number of ff, fl and fi = 3
*/
int main() {
  int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, vowelCnt = 0;
  int spaceCnt = 0, tabCnt = 0, newlineCnt = 0;
  int doubleCnt = 0;
  string inStr;
  string doubleStr;

  cout << "Enter your text (EOF to exit):" << endl;
  while (getline(cin, inStr)) {
    // NOTE: We can store the previous iterator value in the for-loop
    for (auto it = inStr.begin(), prev_it = inStr.end(); it != inStr.end();
         prev_it = it, ++it) {
      switch (*it) {
        case 'a':
        case 'A':
          ++aCnt;
          break;
        case 'e':
        case 'E':
          ++eCnt;
          break;
        case 'i':
        case 'I':
          ++iCnt;
          break;
        case 'o':
        case 'O':
          ++oCnt;
          break;
        case 'u':
        case 'U':
          ++uCnt;
          break;
        case ' ':
          ++spaceCnt;
          break;
        case '\t':
          ++tabCnt;
          break;
      }
      // Check for two character sequences
      if (it != inStr.begin()) {
        /*
         NOTE: Must cast to string in order not to add their values
         We here use the string constructor as static_cast from char to string
         seem not to work
         */
        doubleStr = string(1, *prev_it) + string(1, *it);
        // NOTE: Only int or char can be used in a switch statment
        if (doubleStr == "ff" || doubleStr == "fl" || doubleStr == "fi") {
          ++doubleCnt;
        }
      }
    }
    ++newlineCnt;
  }

  vowelCnt = aCnt + eCnt + iCnt + oCnt + uCnt;
  cout << "Number of a = " << aCnt << endl;
  cout << "Number of e = " << eCnt << endl;
  cout << "Number of i = " << iCnt << endl;
  cout << "Number of o = " << oCnt << endl;
  cout << "Number of u = " << uCnt << endl;
  cout << "Number of vowels = " << vowelCnt << endl;
  cout << endl;
  cout << "Number of spaces = " << spaceCnt << endl;
  cout << "Number of tabs = " << tabCnt << endl;
  cout << "Number of newlines = " << newlineCnt << endl;
  cout << endl;
  cout << "Number of ff, fl and fi = " << doubleCnt << endl;
  cout << endl;

  return 0;
}
