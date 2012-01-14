#define BOOST_TEST_MODULE CodingDojo18
#include <boost/test/included/unit_test.hpp>

#include <string>
#include <vector>

using namespace std;

string evaluate(vector<int> hand)
{
    sort(hand.begin(), hand.end());
    bool first_three_rolls_are_equal = hand[0] == hand[1] && hand[1] == hand[2];
    bool last_three_rolls_are_equal = hand[2] == hand[3] && hand[3] == hand[4];
    bool first_four_rolls_are_equal = hand[1] == hand[2] && hand[2] == hand[3] && hand[0] == hand[1];
    bool last_four_rolls_are_equal = hand[1] == hand[2] && hand[2] == hand[3] && hand[3] == hand[4];
    if (hand[0] == hand[1] && last_four_rolls_are_equal)
        {return "FIVE";}
    else if (last_four_rolls_are_equal)
        {return "FOUR";}
    else if (first_four_rolls_are_equal)
        {return "FOUR";}
    else if (first_three_rolls_are_equal)
        {return "FULL";}
    else if (last_three_rolls_are_equal)
        {return "FULL";}
    else {return "";}
}

std::vector<int> mkvector(int a, int b, int c, int d, int e)
{
    vector<int> result(5);
    result[0] = a;
    result[1] = b;
    result[2] = c;
    result[3] = d;
    result[4] = e;
    return result;
}
BOOST_AUTO_TEST_SUITE(BOOST_TEST_MODULE)

BOOST_AUTO_TEST_CASE(evaluate_5_5_5_5_5_return_FIVE)
{
    vector<int> hand( mkvector( 5, 5, 5, 5, 5 ) );
    hand[0] = 5; hand[1] = 5; hand[2] = 5; hand[3] = 5; hand[4] = 5;
    BOOST_CHECK_EQUAL("FIVE", evaluate(hand));
}

BOOST_AUTO_TEST_CASE(evaluate_1_1_5_5_5_return_FULL)
{
    vector<int> hand(5);
    hand[0] = 1; hand[1] = 1; hand[2] = 5; hand[3] = 5; hand[4] = 5;
    BOOST_CHECK_EQUAL("FULL", evaluate(hand));
}

BOOST_AUTO_TEST_CASE(evaluate_1_1_1_5_5_return_FULL)
{
    vector<int> hand(5);
    hand[0] = 1; hand[1] = 1; hand[2] = 1; hand[3] = 5; hand[4] = 5;
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

BOOST_AUTO_TEST_CASE(evaluate_1_2_3_4_5_return_EMPTY)
{
    vector<int> hand(5);
    hand[0] = 1; hand[1] = 2; hand[2] = 3; hand[3] = 4; hand[4] = 5;
    BOOST_CHECK_EQUAL("", evaluate(hand));
}


BOOST_AUTO_TEST_SUITE_END()
#undef BOOST_TEST_MODULE

