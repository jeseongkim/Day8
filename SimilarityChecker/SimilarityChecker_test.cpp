#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"
using namespace testing;

TEST(SimilarityChecker, SameLength){
	SimilarityChecker checker;
	string leftStr = "ABC";
	string rightStr = "DEF";
	int result = checker.getLengthResult(leftStr, rightStr);
	EXPECT_EQ(60, result);
}



int main() {
	testing::InitGoogleMock();

	return RUN_ALL_TESTS();
}