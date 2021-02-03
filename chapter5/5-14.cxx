#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;

#include <string>
using std::string;

#include <sstream>
using std::stringstream;

#include <vector>
using std::vector;

#include <map>
using std::map;

/*
Test
how now now now brown cow cow brown now now now now brown brown now now

brown repeated max 2 times
cow repeated max 2 times
now repeated max 4 times
*/
int main() {
  int curDuplicate = 1;  // Initialize to 1 as the first word in a series of
                         // repetition must be counted
  string inStr, buffer;
  vector<string> words;
  map<string, int> wordCount;
  map<string, int> maxRepetition;

  /* From
  Split text into word tokens, from
  https://stackoverflow.com/a/5208977/2786884
  */
  cout << "Enter your text (EOF to exit):" << endl;
  while (getline(cin, inStr)) {
    stringstream stream(inStr);
    while (getline(stream, buffer, ' ')) {
      words.push_back(buffer);
    }
  }

  cout << "\nYou entered: " << endl;
  for (auto const &word : words) {
    cout << word << endl;
  }
  cout << endl;

  // Loop through the words
  for (auto const &word : words) {
    if (wordCount.find(word) == wordCount.end()) {
      // The word is not found in the map
      wordCount[word] = 1;
    } else {
      // The word is found in the map
      wordCount[word] += 1;
    }
  }

  // Loop through the map
  for (auto const &mapElement : wordCount) {
    cout << mapElement.first << " counted " << mapElement.second << " times"
         << endl;
  }
  cout << endl;

  // Check for repetitions
  for (auto curWord = words.begin(), prevWord = words.end();
       curWord != words.end(); prevWord = curWord, ++curWord) {
    if (*curWord == *prevWord) {
      curDuplicate += 1;
      // The word is found in the map
      if (curDuplicate > maxRepetition[*curWord]) {
        maxRepetition[*curWord] = curDuplicate;
      }
    } else {
      curDuplicate = 1;
    }
  }

  // Loop through the map
  for (auto const &mapElement : maxRepetition) {
    cout << mapElement.first << " repeated max " << mapElement.second
         << " times" << endl;
  }
  cout << endl;

  return 0;
}
