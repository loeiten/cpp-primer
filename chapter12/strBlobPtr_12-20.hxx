#ifndef CHAPTER12_STRBLOBPTR_12_20_HXX_
#define CHAPTER12_STRBLOBPTR_12_20_HXX_

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;
using std::weak_ptr;

class StrBlob;

class StrBlobPtr {
 public:
  // Constructors
  StrBlobPtr();
  explicit StrBlobPtr(const StrBlob& a, string::size_type sz = 0);
  // Dereference
  string& deref() const;
  // Increment
  StrBlobPtr& incr();

 private:
  shared_ptr<vector<string>> check(string::size_type i,
                                   const string& msg) const;
  weak_ptr<vector<string>> wptr;
  string::size_type curr;
};

#endif  // CHAPTER12_STRBLOBPTR_12_20_HXX_
