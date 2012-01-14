#define BOOST_TEST_MODULE CodingDojo18
#include <boost/test/included/unit_test.hpp>

#include <string>
#include <vector>

std::string evaluate(std::vector<int>)
{
    return "FIVE";
}

BOOST_AUTO_TEST_SUITE(BOOST_TEST_MODULE)

BOOST_AUTO_TEST_CASE(evaluate_5_5_5_5_5_return_FIVE)
{
    std::vector<int> hand(5);
    hand[0] = 5;
    hand[1] = 5;
    hand[2] = 5;
    hand[3] = 5;
    hand[4] = 5;
    BOOST_CHECK_EQUAL("FIVE", evaluate(hand));
}

BOOST_AUTO_TEST_SUITE_END()
#undef BOOST_TEST_MODULE

