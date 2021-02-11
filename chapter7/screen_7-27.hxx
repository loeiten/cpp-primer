#ifndef CHAPTER7_SCREEN_7_27_HXX_
#define CHAPTER7_SCREEN_7_27_HXX_

#include <iostream>
using std::ostream;

#include <string>
using std::string;

class Screen {
 public:
  // Definitions
  typedef string::size_type pos;

  // Constructors
  Screen() = default;
  Screen(pos ht, pos wd) : width(wd), contents(ht * wd, ' ') {}
  Screen(pos ht, pos wd, char c) : width(wd), contents(ht * wd, c) {}

  // Displays
  Screen& display(ostream& os) {
    do_display(os);
    return *this;
  }
  const Screen& display(ostream& os) const {
    do_display(os);
    return *this;
  }

  // Get operations
  char getCursor() const { return contents[cursor]; }
  // NOTE: We explicitly say that this function is inline as the definition is
  // not in the class declaration
  inline char getCursor(pos ht, pos wd) const;

  // Set operations
  Screen& set(char);
  Screen& set(pos, pos, char);

  // Move operations
  Screen& moveCursor(pos r, pos c);

 private:
  pos cursor = 0, width = 0;
  string contents;

  void do_display(ostream& os) const { os << contents; }
};

#endif  // CHAPTER7_SCREEN_7_27_HXX_
