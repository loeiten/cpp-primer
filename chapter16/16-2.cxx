#include <iostream>
using std::cout;
using std::endl;

#include <ostream>
using std::ostream;

#include <map>
using std::map;

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;

#include <vector>
using std::vector;

#include <initializer_list>
using std::initializer_list;

template <typename T>
int greaterThan(const T& a, const T& b) {
  if (b < a) {
    return 1;
  }
  if (a < b) {
    return -1;
  }
  return 0;
}

template <typename T>
void compare(const T& a, const T& b) {
  static map<int, string> compareMap;
  compareMap[1] = " is greater than ";
  compareMap[-1] = " is less than ";
  compareMap[0] = " is equal to ";

  cout << a << compareMap[greaterThan<T>(a, b)] << b << endl;
}

template <typename T>
class MyVector {
  template <typename Q>  // NOTE: Without this we get linker problems
  friend ostream& operator<<(ostream&, const MyVector<Q>&);

 public:
  explicit MyVector(initializer_list<T> li) {
    for (const auto& el : li) {
      v.push_back(el);
    }
  }

  bool operator<(const MyVector<T>& rhs) const { return this->v < rhs.v; }

 private:
  vector<T> v;
};

template <typename T>
ostream& operator<<(ostream& os, const MyVector<T>& mv) {
  ostringstream outStream;
  outStream << "[";
  for (const auto& el : mv.v) {
    outStream << el << ", ";
  }
  // https://stackoverflow.com/a/26492431/2786884
  outStream.seekp(-2, outStream.cur);
  outStream << "]";
  string str = outStream.str();
  os << str.substr(0,
                   str.size() - 1);  // Removing the last space from the string
  return os;
}

int main() {
  compare(0, 1);
  compare(1.0, 0.0);
  compare("hello", "world");
  compare('b', 'b');
  // NOTE: Call by reference guarantess that objects will not be copied
  compare(MyVector<int>{1, 2, 3}, MyVector<int>{1, 2, 1});
  compare(MyVector<int>{1, 2, 3}, MyVector<int>{1, 9});
  return 0;
}
