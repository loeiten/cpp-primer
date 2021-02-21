#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iterator>
using std::back_inserter;

#include <algorithm>
using std::copy;
using std::find;

#include <map>
using std::map;

#include <vector>
using std::vector;

#include <string>
using std::getline;
using std::string;

int main() {
  map<string, vector<string>> family;
  string familyName;
  string givenName;
  string line;
  const string msg =
      "Enter name on the form\n\"lastName, firstName midleName\"";

  cout << msg << endl;
  while (getline(cin, line)) {
    const auto stringBeg = line.cbegin();
    const auto stringEnd = line.cend();
    /*
     * NOTE: Cannot do
     *       const auto commaIterator = find(stringBeg, stringEnd, ", ")
     *       As this would compare 'char' and 'const char *'
     *       Will therefore find index and cast to iterator
     */
    const auto commaIndex = line.find(", ");
    if (commaIndex == string::npos) {
      cout << "\nNo comma and space detected" << endl;
    } else {
      // Casting from size_type (unsigned) to difference_type (signed)
      const auto commaIterator =
          stringBeg + static_cast<std::string::difference_type>(commaIndex);
      // NOTE: Last iterator in copy is non-inclusive
      copy(stringBeg, commaIterator, back_inserter(familyName));
      // NOTE: +2 as we would like to skip , and space
      copy(commaIterator + 2, stringEnd, back_inserter(givenName));

      family[familyName].push_back(givenName);

      // As we back_insert, we need to clear the names
      familyName.clear();
      givenName.clear();
    }
    cout << "\n" << msg << endl;
  }

  cout << "\n\nPrinting family names" << endl;
  for (const auto& mapEl : family) {
    cout << "\nFamily name: " << mapEl.first << endl;
    for (const auto& vecEl : mapEl.second) {
      cout << vecEl << endl;
    }
  }
  return 0;
}
