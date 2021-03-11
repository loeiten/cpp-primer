#include <boost/test/unit_test.hpp>

#include "multiply.hxx"

BOOST_AUTO_TEST_SUITE(Multiply)

BOOST_AUTO_TEST_CASE(simple_multiply_test) { BOOST_TEST(multiply(1, 1) == 1); }

BOOST_AUTO_TEST_CASE(advanced_multiply_test) {
  BOOST_TEST(multiply(1, -1) == -1);
}

BOOST_AUTO_TEST_SUITE_END()
