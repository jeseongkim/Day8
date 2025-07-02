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

TEST_F(SimilarityCheckerFixture, LengthCheck){
	checkLengthTest("ABC", "ABC", 60);	
	checkLengthTest("ABC", "EF", 30);	
	checkLengthTest("ABC", "", 0);
}

int main() {
	testing::InitGoogleMock();

	return RUN_ALL_TESTS();
}