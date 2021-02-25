#include "strBlobPtr_12-20.hxx"

#include <initializer_list>

// NOTE: It looks like this is messing up the order of imports...although this
// happens automatically by the CI
#include "strBlob_12-20.hxx"
using std::initializer_list;

#include <vector>  // NOLINT
using std::vector;

#include <string>  // NOLINT
using std::string;

#include <memory>  // NOLINT
using std::shared_ptr;

#include <exception>  // NOLINT
using std::out_of_range;
using std::runtime_error;

// StrBlobPtr
// Public
// Constructors
StrBlobPtr::StrBlobPtr() : wptr(), curr(0) {}
StrBlobPtr::StrBlobPtr(const StrBlob& a, string::size_type sz)
    : wptr(a.data), curr(sz) {}
// Dereference
string& StrBlobPtr::deref() const {
  auto p = check(curr, "dereference past end");
  return (*p)[curr];
}
// Increment
StrBlobPtr& StrBlobPtr::incr() {
  check(curr, "increment past end");
  ++curr;
  return *this;
}

// Private
shared_ptr<vector<string>> StrBlobPtr::check(string::size_type i,
                                             const string& msg) const {
  auto ret = wptr.lock();
  if (!ret) {
    throw runtime_error("unbound StrBlobPtr");
  }
  if (i >= ret->size()) {
    throw out_of_range(msg);
  }
  return ret;
}
