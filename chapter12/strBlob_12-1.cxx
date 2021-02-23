#include "strBlob_12-1.hxx"

#include <initializer_list>
using std::initializer_list;

#include <string>
using std::string;

#include <exception>
using std::out_of_range;

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

// Private
void StrBlob::check(string::size_type i, const string& msg) const {
  if (i >= size()) {
    throw out_of_range(msg);
  }
}
