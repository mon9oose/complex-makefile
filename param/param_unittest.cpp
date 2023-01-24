#define BOOST_TEST_DYN_LINK

#include "boost/test/unit_test.hpp"
#include "param.hpp"

BOOST_AUTO_TEST_SUITE(ParamUnittest)

BOOST_AUTO_TEST_CASE(Constructor)
{
    BOOST_CHECK_NE(nullptr, nullptr);
}

BOOST_AUTO_TEST_CASE(globalVariable)
{
    BOOST_CHECK_EQUAL(param->GetParam1(), "a");
}

BOOST_AUTO_TEST_SUITE_END()