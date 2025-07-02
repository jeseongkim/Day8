#include "gmock/gmock.h"
#include "Baseball.cpp"

using namespace testing;
class BaseballFixture : public Test {
public:
	Baseball game;
	void assertIllegalArgument(string guessNumber) {
		try {
			game.guess(string(guessNumber));
			FAIL();
		}
		catch (exception e) {
			// PASS
		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase){
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

int main() {
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}