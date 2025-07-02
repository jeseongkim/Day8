#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"
using namespace testing;

class SimilarityCheckerFixture : public Test {
public:
	SimilarityChecker checker;

	void checkLengthTest(string leftStr, string rightStr, double expected) {
		EXPECT_EQ(expected, checker.getLengthResult(leftStr, rightStr));
	}

};

TEST_F(SimilarityCheckerFixture, SameLength){
	string leftStr = "ABC";
	string rightStr = "DEF";
	checkLengthTest(leftStr, rightStr, 60);	
}

TEST_F(SimilarityCheckerFixture, PartialLength){
	string leftStr = "ABC";
	string rightStr = "EF";
	checkLengthTest(leftStr, rightStr, 30);	
}

TEST_F(SimilarityCheckerFixture, ZeroLength){
	string leftStr = "ABC";
	string rightStr = "";
	checkLengthTest(leftStr, rightStr, 0);
}

int main() {
	testing::InitGoogleMock();

	return RUN_ALL_TESTS();
}