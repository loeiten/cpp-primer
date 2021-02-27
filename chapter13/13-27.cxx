#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <memory>
using std::make_shared;
using std::shared_ptr;

#include <cstddef>
using std::size_t;

class HasPtr {
 public:
  // NOTE: ps(&string(s)) would take the adress of the temporary object
  //       new returns a pointer to the object it allocates
  explicit HasPtr(const string& s = string())
      : ps(new string(s)), useCount(new size_t(1)), i(0) {
    cout << "HasPtr(const string& s=string())" << endl;
    cout << "useCount = " << *useCount << endl;
  }

  HasPtr(const HasPtr& hp) : ps(hp.ps), useCount(hp.useCount), i(hp.i) {
    ++*useCount;
    cout << "HasPtr(const HasPtr& hp)" << endl;
    cout << "useCount = " << *useCount << endl;
  }

  ~HasPtr() {
    cout << "~HasPtr(), with useCount before decrease = " << *useCount << "\n"
         << endl;
    if (--*useCount == 0) {
      delete ps;
      delete useCount;
    }
  }

  HasPtr& operator=(const HasPtr& rhs) {
    cout << "HasPtr& operator= (const HasPtr& rhs)" << endl;
    cout << "rhs.useCount before increase = " << *rhs.useCount << endl;
    cout << "useCount before decrease = " << *useCount << endl;
    ++*rhs.useCount;
    if (--*useCount == 0) {
      delete ps;
      delete useCount;
    }
    ps = rhs.ps;
    i = rhs.i;
    useCount = rhs.useCount;
    return *this;
  }

  void print() const { cout << *ps << endl; }

 private:
  string* ps;
  size_t* useCount;
  int i;
};

int main() {
  cout << "HasPtr foo" << endl;
  HasPtr foo;

  cout << "\nHasPtr bar(\"bar\")" << endl;
  HasPtr bar("bar");

  cout << "\nfoo = bar" << endl;
  foo = bar;

  cout << "\nHasPtr baz = foo" << endl;
  HasPtr baz = foo;
  cout << "baz.print() = ";
  baz.print();

  cout << "\nGoing out of scope" << endl;
  return 0;
}
