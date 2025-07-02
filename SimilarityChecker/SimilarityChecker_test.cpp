#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"
using namespace testing;

TEST(SimilarityChecker, SameLength){
	SimilarityChecker checker;
	string leftStr = "ABC";
	string rightStr = "DEF";
	double result = checker.getLengthResult(leftStr, rightStr);
	EXPECT_EQ(60, result);
}

TEST(SimilarityChecker, PartialLength){
	SimilarityChecker checker;
	string leftStr = "ABC";
	string rightStr = "EF";
	double result = checker.getLengthResult(leftStr, rightStr);
	EXPECT_EQ(30, result);
}



int main() {
	testing::InitGoogleMock();

	return RUN_ALL_TESTS();
}