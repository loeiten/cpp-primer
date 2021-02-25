#ifndef CHAPTER12_STRBLOB_12_20_HXX_
#define CHAPTER12_STRBLOB_12_20_HXX_

#include <initializer_list>
using std::initializer_list;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <memory>
using std::make_shared;
using std::shared_ptr;

class StrBlobPtr;

class StrBlob {
  friend class StrBlobPtr;

 public:
  // Constructors
  // NOTE: We always initialize data in order not to get segmentation faults
  StrBlob() { data = make_shared<vector<string>>(); }
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
  StrBlobPtr begin();
  StrBlobPtr end();
  const string& front() const;
  const string& back() const;

 private:
  shared_ptr<vector<string>> data;
  void check(string::size_type i, const string& msg) const;
};

#endif  // CHAPTER12_STRBLOB_12_20_HXX_
