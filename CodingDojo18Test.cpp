#define BOOST_TEST_MODULE CodingDojo18
#include <boost/test/included/unit_test.hpp>

#include <string>
#include <vector>

using namespace std;

string evaluate(vector<int> hand)
{
    sort(hand.begin(), hand.end());
    const int number_of_pairs = 4;
    //    vector<bool> two_consecutive_are_equal_from(number_of_pairs);
    vector<int> number_of_tuples(4);
    number_of_tuples[1] = 4;
    number_of_tuples[2] = 3;
    number_of_tuples[3] = 2;
    number_of_tuples[4] = 1;
    vector<bool> two_consecutive_are_equal_from(number_of_pairs);
    for (int i = 0; i < number_of_pairs; ++i)
        two_consecutive_are_equal_from[i] = hand[i] == hand[i+1];
    const int number_of_triplets = 3;
    vector<bool> three_consecutive_are_equal_from(number_of_triplets);
    for (int i = 0; i < number_of_triplets; ++i)
        three_consecutive_are_equal_from[i] = hand[i] == hand[i+1] && hand[i+1] == hand[i+2];
    const int number_of_quads = 2;
    vector<bool> four_consecutive_are_equal_from(number_of_quads);
    for (int i = 0; i < number_of_quads; ++i)
        four_consecutive_are_equal_from[i] = hand[i] == hand[i+1] && hand[i+1] == hand[i+2]
            && hand[i + 2] == hand[i + 3] ;

    if (two_consecutive_are_equal_from[0] && four_consecutive_are_equal_from[1])
        {return "FIVE";}
    else if (four_consecutive_are_equal_from[0])
        {return "FOUR";}
    else if (four_consecutive_are_equal_from[1])
        {return "FOUR";}
    else if (three_consecutive_are_equal_from[0]) {
        if (two_consecutive_are_equal_from[3])
            {return "FULL";}
        return "THREE";
    }
    else if (three_consecutive_are_equal_from[2]) {
        if (two_consecutive_are_equal_from[0]) {
            return "FULL";
        }
        return "THREE";
    }
    else if (three_consecutive_are_equal_from[1])
        {
            return "THREE";
        }
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

BOOST_AUTO_TEST_CASE(evaluate_1_2_5_5_5_return_THREE)
{
    vector<int> hand(mkvector(1, 2, 5, 5, 5));
    BOOST_CHECK_EQUAL("THREE", evaluate(hand));
}

BOOST_AUTO_TEST_CASE(evaluate_1_3_3_3_5_return_THREE)
{
    vector<int> hand(mkvector(1, 3, 3, 3, 5));
    BOOST_CHECK_EQUAL("THREE", evaluate(hand));
}

BOOST_AUTO_TEST_SUITE_END()
#undef BOOST_TEST_MODULE

