#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <utility>
using std::pair;

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
using std::stoi;
using std::string;

bool subStringExist(const string::size_type& index) {
  if (index == string::npos) {
    cout << "\nNo comma and space detected" << endl;
    return false;
  }
  return true;
}

int main() {
  map<string, vector<pair<string, unsigned int>>> family;
  int age = 0;
  string familyName;
  string givenName;
  string line;
  const string msg =
      "Enter name on the form\n\"lastName, firstName midleName, age\"";

  cout << msg << endl;
  while (getline(cin, line)) {
    const auto stringBeg = line.cbegin();
    const auto stringEnd = line.cend();
    /*
     * NOTE: Cannot do
     *       const auto nameIterator = find(stringBeg, stringEnd, ", ")
     *       As this would compare 'char' and 'const char *'
     *       Will therefore find index and cast to iterator
     */
    const auto commaNameIndex = line.find(", ");
    if (subStringExist(commaNameIndex)) {
      // Casting from size_type (unsigned) to difference_type (signed)
      const auto nameIterator =
          stringBeg + static_cast<std::string::difference_type>(commaNameIndex);
      // NOTE: Last iterator in copy is non-inclusive
      copy(stringBeg, nameIterator, back_inserter(familyName));

      const auto commaAgeIndex = line.find(", ", commaNameIndex + 1);
      if (subStringExist(commaAgeIndex)) {
        // NOTE: +2 as we would like to skip , and space
        // NOTE: Last iterator in copy is non-inclusive
        const auto ageIterator =
            stringBeg +
            static_cast<std::string::difference_type>(commaAgeIndex);
        copy(nameIterator + 2, ageIterator, back_inserter(givenName));
        age = stoi(string(ageIterator + 2, stringEnd));

        family[familyName].push_back({givenName, age});
      }

      // As we back_insert, we need to clear the names
      familyName.clear();
      givenName.clear();
      age = 0;
    }
    cout << "\n" << msg << endl;
  }

  cout << "\n\nPrinting family names" << endl;
  for (const auto& mapEl : family) {
    cout << "\nFamily name: " << mapEl.first << endl;
    for (const auto& pairEl : mapEl.second) {
      cout << pairEl.first << ", " << pairEl.second << endl;
    }
  }
  return 0;
}
