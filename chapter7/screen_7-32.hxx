#ifndef CHAPTER7_SCREEN_7_32_HXX_
#define CHAPTER7_SCREEN_7_32_HXX_

#include <iostream>
using std::ostream;

#include <string>
using std::string;

class Screen {
  /*
  NOTE: In an ideal world, we would only friend the function
        friend void Window_mgr::clear(ScreenIndex);
        However, this needs restructuring of the program

        1. First, define the Window_mgr class, which declares, but cannot
  define, clear. Screen must be declared before clear can use the members of
  Screen.
        2. Next, define class Screen, including a friend declaration for clear.
        3. Finally, define clear, which can now refer to the members in Screen.

        The options mentioned in
        https://stackoverflow.com/a/52325764/2786884
        works only if Window_mgr does not have Screen as a private member
  */
  friend class Window_mgr;

 public:
  // Definitions
  typedef string::size_type pos;

  // Constructors
  Screen() = default;
  Screen(pos ht, pos wd) : heigth(ht), width(wd), contents(ht * wd, ' ') {}
  Screen(pos ht, pos wd, char c)
      : heigth(ht), width(wd), contents(ht * wd, c) {}

  // Displays
  Screen display(ostream& os) {
    do_display(os);
    return *this;
  }
  const Screen display(ostream& os) const {
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
  pos cursor = 0, heigth = 0, width = 0;
  string contents;

  void do_display(ostream& os) const { os << contents; }
};

#endif  // CHAPTER7_SCREEN_7_32_HXX_
