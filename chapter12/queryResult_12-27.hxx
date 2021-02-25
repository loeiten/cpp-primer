#ifndef CHAPTER12_QUERYRESULT_12_27_HXX_
#define CHAPTER12_QUERYRESULT_12_27_HXX_

#include <iostream>
using std::ostream;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <set>
using std::set;

#include <memory>
using std::shared_ptr;

class QueryResult {
  friend ostream& print(ostream&, const QueryResult);

 public:
  using lineNoSize = vector<string>::size_type;
  QueryResult(string q, shared_ptr<set<lineNoSize>> l,
              shared_ptr<vector<string>> f)
      : query(q), lines(l), file(f) {}

 private:
  string query;
  shared_ptr<set<lineNoSize>> lines;
  shared_ptr<vector<string>> file;
};

ostream& print(ostream&, const QueryResult);

#endif  // CHAPTER12_QUERYRESULT_12_27_HXX_
