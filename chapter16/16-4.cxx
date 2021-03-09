#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <string>
using std::string;
using std::to_string;

#include <iterator>
using std::distance;

template <typename IT, typename U>
IT find(IT it, const IT& end, const U& val) {
  for (; it != end; ++it) {
    if (*it == val) {
      return it;
    }
  }
  return end;
}

template <typename T, typename U>
void findAndPrint(const T& cont, const U& val) {
  // NOTE: Must use this scope to not get ambiguous call
  auto iterator = ::find(cont.begin(), cont.end(), val);
  // NOTE: As list does not have random access iterator, we cannot do
  //       iterator - cont.begin()
  cout << val
       << (iterator == cont.end()
               ? " not found"
               : (" found at index " +
                  to_string(distance(cont.begin(), iterator))))
       << endl;
}

int main() {
  vector<int> v{1, 2, 3};
  findAndPrint(v, 1);
  findAndPrint(v, 3);
  findAndPrint(v, 0);

  cout << endl;

  list<string> s{"hello", "hi", "good day"};
  findAndPrint(s, "hello");
  findAndPrint(s, "hi");
  findAndPrint(s, "bye");
  return 0;
}
