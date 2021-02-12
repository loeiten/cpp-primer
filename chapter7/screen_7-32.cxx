#include "screen_7-32.hxx"

// NOTE: For these operations to be inlined, they must be specified togehter
// with the header See https://stackoverflow.com/a/9648694/2786884
// https://stackoverflow.com/a/9338189/2786884

// NOTE: C++ has no idea of 2-dimensions. Thus, in order to get the correct
// position we must multiply with how many characters which fits into one width
// to get the character number corresponding to that character

// Get operations
char Screen::getCursor(pos r, pos c) const {
  pos row = r * width;  // See explanation on top
  return contents[row + c];
}

// Set operations
Screen& Screen::set(char c) {
  contents[cursor] = c;
  return *this;
}

Screen& Screen::set(pos r, pos col, char ch) {
  contents[r * width + col] = ch;
  return *this;
}

// Move operations
Screen& Screen::moveCursor(pos r, pos c) {
  pos row = r * width;  // See explanation on top
  cursor = row + c;
  return *this;
}
