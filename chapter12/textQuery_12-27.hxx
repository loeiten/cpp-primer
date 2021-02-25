#ifndef CHAPTER12_TEXTQUERY_12_27_HXX_
#define CHAPTER12_TEXTQUERY_12_27_HXX_

#include <fstream>
using std::ifstream;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <memory>
using std::shared_ptr;

#include <map>
using std::map;

#include <set>
using std::set;

class QueryResult;

class TextQuery {
 public:
  using lineNoSize = vector<string>::size_type;
  explicit TextQuery(ifstream&);
  QueryResult query(const string&) const;

 private:
  shared_ptr<vector<string>> file;
  map<string, shared_ptr<set<lineNoSize>>> words;
};

#endif  // CHAPTER12_TEXTQUERY_12_27_HXX_
