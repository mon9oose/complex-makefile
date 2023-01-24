#define BOOST_TEST_MODULE Test111
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_NO_MAIN

#include "boost/test/unit_test.hpp"
#include "param/param.hpp"

// struct ParamGlobalFixture
// {
//     ParamGlobalFixture()
//     {
//         BOOST_TEST_MESSAGE("construct ParamGlobalFixture");
//     }
//     ~ParamGlobalFixture()
//     {
//         BOOST_TEST_MESSAGE("destory ParamGlobalFixture");
//         delete param;
//     }

//     static Param *param;
//     static int i;
// };

// int ParamGlobalFixture::i = 0;
// Param *ParamGlobalFixture::param = new Param("a", "b", "c", "d");

// BOOST_TEST_GLOBAL_FIXTURE(ParamGlobalFixture);

// BOOST_AUTO_TEST_CASE(test_case1)
// {
//   BOOST_TEST_MESSAGE("running test_case1");
//   BOOST_TEST(ParamGlobalFixture::i == 1);
// }

// BOOST_AUTO_TEST_CASE(test_case2)
// {
//   BOOST_TEST_MESSAGE("running test_case2");
//   BOOST_TEST(ParamGlobalFixture::i == 3);
// }

// BOOST_AUTO_TEST_CASE(test_case3)
// {
//   BOOST_TEST_MESSAGE("running test_case3");
//   BOOST_TEST(ParamGlobalFixture::param->GetParam1() == "a");
// }

UP_PARAM param(new Param("a", "b", "c", "d"));

int main(int argc, char *argv[], char *envp[])
{
    return boost::unit_test::unit_test_main(&init_unit_test, argc, argv);
}