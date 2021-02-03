#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

int main() {
  vector<string> svec{"hello", "world", "are you", "fine", "today?"};
  // Just checking that this works fine
  for (auto s = svec.begin(); s != svec.end(); ++s) {
    cout << *s << endl;
  }
  cout << "\n" << endl;

  vector<string>::iterator iter = svec.begin();
  cout << *iter++ << endl;
  cout << *iter << endl;

  // Cannot increment a string
  // cout << (*iter)++ << endl;

  // Checks whether iter is empty, then derefence the result
  // cout << *iter.empty() << endl;

  // Dereference iter and checks if it's empty (it's not empty as the word is
  // 'world')
  cout << iter->empty() << endl;

  // ++ has presedence over *, so here trying to increment a string
  // cout << ++*iter << endl;

  // Increments the iterator to 'are you', then check if this is empty
  cout << iter++->empty() << endl;
  return 0;
}
