#define BOOST_TEST_MODULE CodingDojo18
#include <boost/test/included/unit_test.hpp>

#include <string>
#include <vector>

using namespace std;

string evaluate(vector<int> hand)
{
    sort(hand.begin(), hand.end());
    bool last_four_rolls_are_equal = hand[1] == hand[2] && hand[2] == hand[3] && hand[3] == hand[4];
    if (hand[0] == hand[1] && last_four_rolls_are_equal)
        {return "FIVE";}
    else if (hand[0] != hand[1] && last_four_rolls_are_equal)
        {return "FOUR";}
    else {return "FULL";}
}

BOOST_AUTO_TEST_SUITE(BOOST_TEST_MODULE)

BOOST_AUTO_TEST_CASE(evaluate_5_5_5_5_5_return_FIVE)
{
    vector<int> hand(5);
    hand[0] = 5;
    hand[1] = 5;
    hand[2] = 5;
    hand[3] = 5;
    hand[4] = 5;
    BOOST_CHECK_EQUAL("FIVE", evaluate(hand));
}

BOOST_AUTO_TEST_CASE(evaluate_1_1_5_5_5_return_FULL)
{
    vector<int> hand(5);
    hand[0] = 1;
    hand[1] = 1;
    hand[2] = 5;
    hand[3] = 5;
    hand[4] = 5;
    BOOST_CHECK_EQUAL("FULL", evaluate(hand));
}

BOOST_AUTO_TEST_CASE(evaluate_1_5_5_5_5_return_FOUR)
{
    vector<int> hand(5);
    hand[0] = 1;
    hand[1] = 5;
    hand[2] = 5;
    hand[3] = 5;
    hand[4] = 5;
    BOOST_CHECK_EQUAL("FOUR", evaluate(hand));
}

BOOST_AUTO_TEST_CASE(evaluate_5_1_5_5_5_return_FOUR)
{
    vector<int> hand(5);
    hand[0] = 5;
    hand[1] = 1;
    hand[2] = 5;
    hand[3] = 5;
    hand[4] = 5;
    BOOST_CHECK_EQUAL("FOUR", evaluate(hand));
}

BOOST_AUTO_TEST_CASE(evaluate_1_1_1_1_5_return_FOUR)
{
    vector<int> hand(5);
    hand[0] = 1;
    hand[1] = 1;
    hand[2] = 1;
    hand[3] = 1;
    hand[4] = 5;
    BOOST_CHECK_EQUAL("FOUR", evaluate(hand));
}

BOOST_AUTO_TEST_SUITE_END()
#undef BOOST_TEST_MODULE

