#include <stdexcept>
#include<iostream>
using namespace std;

class GuessResult {
public:
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question) : question(question) {};

	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		if (guessNumber == question) {
			return { true, 3, 0 };
		}

		int strikes = getStrikes(guessNumber);
        if(strikes == 3) return {true, strikes, 0};

        int balls = 0;
		for (int i = 0; i < guessNumber.length(); i++) {
            for (int j = 0; j < guessNumber.length(); j++) {
                if(i==j) continue;
                if (guessNumber[i] == question[j]) balls++;
            }
		}

		return { false, strikes, balls };
	}

    int getStrikes(string guessNumber){
		int result = 0;
		for (int i = 0; i < guessNumber.length(); i++) {
			if (guessNumber[i] == question[i]) result++;
		}
        return result;
    }

	void assertIllegalArgument(string guessNumber) {
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters.");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number");
		}

		if (isDuplicateNumber(guessNumber)) {
			throw invalid_argument("Must not have same number");
		}
	}
	bool isDuplicateNumber(string guessNumber) {
		return guessNumber[0] == guessNumber[1] || guessNumber[0] == guessNumber[2] || guessNumber[1] == guessNumber[2];
	}
private:
	string question;
};


