#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <memory>
using std::make_shared;
using std::shared_ptr;

class HasPtr {
 public:
  // NOTE: ps(&string(s)) would take the adress of the temporary object
  //       new returns a pointer to the object it allocates
  explicit HasPtr(const string& s = string()) : ps(new string(s)), i(0) {
    cout << "HasPtr(const string& s=string())" << endl;
  }
  HasPtr(const HasPtr& hp) : ps(new string(*hp.ps)), i(hp.i) {
    cout << "HasPtr(const HasPtr& hp)" << endl;
  }
  ~HasPtr() {
    delete ps;
    cout << "~HasPtr() on " << name << "\n" << endl;
  }
  HasPtr& operator=(const HasPtr& rhs) {
    // Copy the underlying string (prevents memleak if assigned to itself)
    auto newPs = new string(*rhs.ps);
    // NOTE: ps has already been allocated by the constructor
    delete ps;
    ps = newPs;
    i = rhs.i;
    cout << "HasPtr& operator= (const HasPtr& rhs)" << endl;
    return *this;
  }
  string name;

 private:
  string* ps;
  int i;
};

void call_by_value(HasPtr foo) {
  foo.name = "copy inside \"call_by_value\"";
  cout << "Inside call_by_value on " << foo.name << endl;
}

void call_by_pointer(HasPtr* foo) {
  cout << "Inside call_by_pointer on " << foo->name << endl;
  cout << "NOTE: Only the pointer is copied when calling by pointer" << endl;
}

void call_by_reference(const HasPtr& foo) {
  cout << "Inside call_by_reference on " << foo.name << endl;
  cout << "NOTE: Nothing is copied on reference calls" << endl;
}

int main() {
  cout << "HasPtr foo" << endl;
  HasPtr foo;
  foo.name = "foo";

  cout << "\nHasPtr bar(\"bar\")" << endl;
  HasPtr bar("bar");
  bar.name = "bar";

  cout << "\nHasPtr baz{\"baz\"}" << endl;
  HasPtr baz{"baz"};
  baz.name = "baz";

  {
    cout << "\nHasPtr fooBar = foo" << endl;
    HasPtr fooBar = foo;
    fooBar.name = "fooBar";

    cout << "\nHasPtr quux(foo)" << endl;
    HasPtr quux(foo);
    quux.name = "quux";

    cout << "\nHasPtr fooBaz" << endl;
    HasPtr fooBaz;
    cout << "fooBaz = foo" << endl;
    fooBaz = foo;
    fooBaz.name = "fooBaz";

    cout << "\nHasPtr* fooPtr = &foo" << endl;
    cout << "NOTE: fooPtr Must point at something" << endl;
    HasPtr* fooPtr = &foo;
    fooPtr->name = "foo which is pointed to by fooPtr";

    cout << "\nauto barPtr = make_shared<HasPtr>(bar)" << endl;
    cout << "NOTE: This calls the constructor" << endl;
    auto barPtr = make_shared<HasPtr>(bar);
    cout << "shared_ptr<HasPtr> barPtrShared = barPtr" << endl;
    shared_ptr<HasPtr> barPtrShared = barPtr;
    barPtrShared->name = "barPtrShared";

    cout << "\nNOTE: fooPtr will not get destroyed when going out of scope as "
            "foo "
            "still exist (only the pointer fooPtr is destroyed)"
         << endl;
    cout << "NOTE: barPtrShared will get destroyed as the shared pointer will "
            "go out of scope\n"
         << endl;
  }

  cout << "HasPtr* bazBarPtr = new HasPtr" << endl;
  cout << "NOTE: This calls the constructor" << endl;
  HasPtr* bazBarPtr = new HasPtr;
  bazBarPtr->name = "bazBarPtr";

  cout << "\ncall_by_value(*bazBarPtr)" << endl;
  call_by_value(*bazBarPtr);

  cout << "\ncall_by_pointer(bazBarPtr)" << endl;
  call_by_pointer(bazBarPtr);

  cout << "\ncall_by_reference(*bazBarPtr)" << endl;
  call_by_reference(*bazBarPtr);

  cout << "\ndelete bazBarPtr" << endl;
  delete bazBarPtr;

  cout << "Going out of scope" << endl;
  return 0;
}
