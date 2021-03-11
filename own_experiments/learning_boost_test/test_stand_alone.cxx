#define BOOST_TEST_MODULE My Test
// NOTE: The below will use the header variant
// #include <boost/test/included/unit_test.hpp>

// NOTE: This will use the static library (the program get's it's own copy of
// the code)
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(first_test) {
  int i = 1;
  BOOST_TEST(i);
  BOOST_TEST(i == 2);
}
