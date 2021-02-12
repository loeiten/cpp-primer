#ifndef CHAPTER7_WINDOW_MGR_7_32_HXX_
#define CHAPTER7_WINDOW_MGR_7_32_HXX_

#include <vector>
using std::vector;

#include "screen_7-32.hxx"

class Window_mgr {
 public:
  using ScreenIndex = std::vector<Screen>::size_type;
  void clear(ScreenIndex);
  Window_mgr& add(Screen* s) {
    screens.push_back(s);
    return *this;
  }
  Screen* get(const ScreenIndex& i) { return screens[i]; }

 private:
  // In order to use the pointer, we need something to point to
  Screen init{24, 80, ' '};
  std::vector<Screen*> screens{&init};
};

#endif  // CHAPTER7_WINDOW_MGR_7_32_HXX_
