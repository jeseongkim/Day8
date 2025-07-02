#include "gmock/gmock.h"
#include "Baseball.cpp"
#include <iostream>

using namespace testing;
class BaseballFixture : public Test {
public:
	Baseball game{"123"};
	void assertIllegalArgument(string guessNumber) {
		try {
			game.guess(string(guessNumber));
			FAIL();
		}
		catch (exception e) {
			// PASS
		}
	}

	void check2Stirkes0Ball(string guessNumber){
		GuessResult result = game.guess(guessNumber);

		EXPECT_FALSE(result.solved);
		EXPECT_EQ(2, result.strikes);
		EXPECT_EQ(0, result.balls);	
	}

	void check1Stirkes2Ball(string guessNumber){
		GuessResult result = game.guess(guessNumber);

		EXPECT_FALSE(result.solved);
		EXPECT_EQ(1, result.strikes);
		EXPECT_EQ(2, result.balls);	
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase){
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber){
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);	
}

TEST_F(BaseballFixture, Strike2Ball0){
	check2Stirkes0Ball("129");
	check2Stirkes0Ball("423");
}

TEST_F(BaseballFixture, Strike1Ball2){
	check1Stirkes2Ball("132");
	check1Stirkes2Ball("321");
}

int main() {
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}