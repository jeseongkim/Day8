#include "gmock/gmock.h"
#include "Baseball.cpp"

using namespace testing;
class BaseballFixture : public Test {
public:
	Baseball game;
	void assetIllegalArgument(string guessNumber) {
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
	assetIllegalArgument("12");
	assetIllegalArgument("12s");
	assetIllegalArgument("121");
}

int main() {
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}