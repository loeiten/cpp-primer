#ifndef CHAPTER12_STRBLOB_12_1_HXX_
#define CHAPTER12_STRBLOB_12_1_HXX_

#include <initializer_list>
using std::initializer_list;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <memory>
using std::make_shared;
using std::shared_ptr;

class StrBlob {
 public:
  // Constructors
  StrBlob() {}
  explicit StrBlob(initializer_list<string> il)
      : data(make_shared<vector<string>>(il)) {}
  // Meta
  string::size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }
  // Add and remove
  void push_back(const string& s) { data->push_back(s); }
  void pop_back();
  // Element access
  string& front();
  string& back();
  const string& front() const;
  const string& back() const;

 private:
  shared_ptr<vector<string>> data;
  void check(string::size_type i, const string& msg) const;
};

#endif  // CHAPTER12_STRBLOB_12_1_HXX_
