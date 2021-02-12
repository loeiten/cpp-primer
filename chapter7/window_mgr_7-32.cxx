#include <string>
using std::string;

#include "window_mgr_7-32.hxx"

void Window_mgr::clear(ScreenIndex i) {
  Screen* s = screens[i];
  s->contents = string(s->heigth * s->width, ' ');
}
