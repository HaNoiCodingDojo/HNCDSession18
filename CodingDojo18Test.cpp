#define BOOST_TEST_MODULE MasterMind
#include <boost/test/included/unit_test.hpp>

#include <vector>

int return_number_good_position_in_sequence(const std::vector<int> & code_sequence,
                                            const std::vector<int> & proposed_sequence)
{
    if (code_sequence == proposed_sequence)
        {
            return 1;
        }
    return 0;
}

BOOST_AUTO_TEST_SUITE(BOOST_TEST_MODULE)

BOOST_AUTO_TEST_CASE(code_sequence_1_proposed_sequence_1_return_1)
{
    std::vector<int> code_sequence(1,1);
    std::vector<int> proposed_sequence(1,1);
    BOOST_CHECK_EQUAL(1, return_number_good_position_in_sequence(code_sequence, proposed_sequence));
}

BOOST_AUTO_TEST_CASE(code_sequence_1_proposed_sequence_2_return_0)
{
    std::vector<int> code_sequence(1,1);
    std::vector<int> proposed_sequence(1,2);
    BOOST_CHECK_EQUAL(0, return_number_good_position_in_sequence(code_sequence, proposed_sequence));
}

BOOST_AUTO_TEST_SUITE_END()
#undef BOOST_TEST_MODULE
