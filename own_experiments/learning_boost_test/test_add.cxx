#define BOOST_TEST_MODULE My Function Test
#include <boost/test/unit_test.hpp>

#include "add.hxx"

BOOST_AUTO_TEST_CASE(simple_test) { BOOST_TEST(add(1, 1) == 2); }

BOOST_AUTO_TEST_CASE(advanced_test) { BOOST_TEST(add(1, -1) == 0); }
