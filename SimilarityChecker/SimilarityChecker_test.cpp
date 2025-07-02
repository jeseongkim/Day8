#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"
using namespace testing;

TEST(SimilarityChecker, SameLength){
	SimilarityChecker s;
	string A = "ABC";
	string B = "DEF";
	int result = s.getLengthResult(A, B);
	EXPECT_EQ(60, result);
}

int main() {
	testing::InitGoogleMock();

	return RUN_ALL_TESTS();
}