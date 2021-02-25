#include "strBlob_12-20.hxx"

#include <initializer_list>

// NOTE: It looks like this is messing up the order of imports...although this
// happens automatically by the CI
#include "strBlobPtr_12-20.hxx"
using std::initializer_list;

#include <string>  // NOLINT
using std::string;

#include <exception>  // NOLINT
using std::out_of_range;

// StrBlob
// Public
// Meta
void StrBlob::pop_back() {
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}
// Element access
string& StrBlob::front() {
  check(0, "front on empty StrBlob");
  return data->front();
}

string& StrBlob::back() {
  check(0, "back on empty StrBlob");
  return data->back();
}

const string& StrBlob::front() const {
  check(0, "front on empty StrBlob");
  return data->front();
}

const string& StrBlob::back() const {
  check(0, "back on empty StrBlob");
  return data->back();
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }

StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

// Private
void StrBlob::check(string::size_type i, const string& msg) const {
  if (i >= size()) {
    throw out_of_range(msg);
  }
}
