#include <vector>
#include <gtest/gtest.h>
#include "general_algorithms.h"

using std::vector;
using general_algorithms::longest_common_subsequence;

void do_lcs_test(vector<int>* xs, vector<int>* ys, vector<int>* exp)
{

	vector<int>* lcs = longest_common_subsequence(xs, ys);

	ASSERT_EQ(lcs->size(), exp->size());

	for (int i = 0; i < lcs->size(); i++)
	{
		ASSERT_EQ(lcs->at(i), exp->at(i));
	}

}

TEST(LongestCommonSubsequence, EmptyBoth)
{

	vector<int> xs = {  };
	vector<int> ys = {  };
	vector<int> exp = {  };

	do_lcs_test(&xs, &ys, &exp);

}

TEST(LongestCommonSubsequence, EmptyLeft)
{

	vector<int> xs = {  };
	vector<int> ys = { 1, 2, 3 };
	vector<int> exp = {  };

	do_lcs_test(&xs, &ys, &exp);

}

TEST(LongestCommonSubsequence, EmptyRight)
{

	vector<int> xs = { 1, 2, 3 };
	vector<int> ys = {  };
	vector<int> exp = {  };

	do_lcs_test(&xs, &ys, &exp);

}

TEST(LongestCommonSubsequence, EqualShort)
{

	vector<int> xs = { 1, 2, 3, 4, 5 };
	vector<int> ys = { 1, 2, 3, 4, 5 };
	vector<int> exp = { 1, 2, 3, 4, 5 };

	do_lcs_test(&xs, &ys, &exp);

}

TEST(LongestCommonSubsequence, EqualLong)
{

	vector<int> xs = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> ys = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> exp = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	do_lcs_test(&xs, &ys, &exp);

}

TEST(LongestCommonSubsequence, ExactSubSequenceStartLeft)
{

	vector<int> xs = { 1, 2, 3 };
	vector<int> ys = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> exp = { 1, 2, 3 };

	do_lcs_test(&xs, &ys, &exp);

}

TEST(LongestCommonSubsequence, ExactSubSequenceMidLeft)
{

	vector<int> xs = { 4, 5, 6 };
	vector<int> ys = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> exp = { 4, 5, 6 };

	do_lcs_test(&xs, &ys, &exp);

}

TEST(LongestCommonSubsequence, ExactSubSequenceStopLeft)
{

	vector<int> xs = { 6, 7, 8 };
	vector<int> ys = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> exp = { 6, 7, 8 };

	do_lcs_test(&xs, &ys, &exp);

}

TEST(LongestCommonSubsequence, ExactSubSequenceStartRight)
{

	vector<int> xs = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> ys = { 1, 2, 3 };
	vector<int> exp = { 1, 2, 3 };

	do_lcs_test(&xs, &ys, &exp);

}

TEST(LongestCommonSubsequence, ExactSubSequenceMidRight)
{

	vector<int> xs = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> ys = { 4, 5, 6 };
	vector<int> exp = { 4, 5, 6 };

	do_lcs_test(&xs, &ys, &exp);

}

TEST(LongestCommonSubsequence, ExactSubSequenceStopRight)
{

	vector<int> xs = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> ys = { 6, 7, 8 };
	vector<int> exp = { 6, 7, 8 };

	do_lcs_test(&xs, &ys, &exp);

}

TEST(LongestCommonSubsequence, General0)
{

	vector<int> xs = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> ys = { 3, 4, 7 };
	vector<int> exp = { 3, 4, 7 };

	do_lcs_test(&xs, &ys, &exp);

}

TEST(LongestCommonSubsequence, General1)
{

	vector<int> xs = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> ys = { 2, 3, 4, 7, 2, 6 };
	vector<int> exp = { 2, 3, 4, 7 };

	do_lcs_test(&xs, &ys, &exp);

}

TEST(LongestCommonSubsequence, General2)
{

	vector<int> xs = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> ys = { 7, 2, 6, 8, 3, 4, 5, 9 };
	vector<int> exp = { 2, 3, 4, 5, 9 };

	do_lcs_test(&xs, &ys, &exp);

}
