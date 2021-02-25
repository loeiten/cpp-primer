#include <iostream>
using std::cout;
using std::endl;

#include <sstream>
using std::istringstream;

#include <fstream>
using std::ifstream;

#include <string>
using std::getline;
using std::string;

#include "queryResult_12-27.hxx"
#include "textQuery_12-27.hxx"

TextQuery::TextQuery(ifstream& inFile) : file(new vector<string>) {
  string line;
  while (getline(inFile, line)) {
    file->push_back(line);
    // Size starts counting from 1
    lineNoSize n = file->size() - 1;
    istringstream lineStream(line);
    string word;
    while (lineStream >> word) {
      // The values of words are shared pointer to a set
      // lines is a reference to that set
      auto& lines = words[word];
      if (!lines) {
        // If the shared pointer is the nullpointer, we allocate a new set of
        // size_type
        lines.reset(new set<lineNoSize>);
      }
      // Insert to the set that the word was found on this line
      lines->insert(n);
    }
  }
}

QueryResult TextQuery::query(const string& q) const {
  static shared_ptr<set<lineNoSize>> nodata(new set<lineNoSize>);
  auto mapIt = words.find(q);
  if (mapIt == words.end()) {
    return QueryResult(q, nodata, file);
  } else {
    return QueryResult(q, mapIt->second, file);
  }
}
