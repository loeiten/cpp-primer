#include <boost/test/unit_test.hpp>

#include "subtract.hxx"

BOOST_AUTO_TEST_SUITE(Subtract)

BOOST_AUTO_TEST_CASE(simple_subtract_test) { BOOST_TEST(subtract(1, 1) == 0); }

BOOST_AUTO_TEST_CASE(advanced_subtract_test) {
  BOOST_TEST(subtract(1, -1) == 2);
}

BOOST_AUTO_TEST_SUITE_END()
