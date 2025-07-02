#include <stdexcept>
#include<iostream>
#include<cmath>
using namespace std;

class SimilarityChecker {
public:
    double getLengthResult(const string leftStr, const string rightStr) {
        if (leftStr.length() == rightStr.length()) return MAX_LENGTH_SCORE;

        double partialScoreRate = getPartialLengthScore(leftStr, rightStr);
        return partialScoreRate;
    }

    double getPartialLengthScore(const string leftStr, const string rightStr) {
        double gap = abs( static_cast<int>(leftStr.length() - rightStr.length()) );
        double minlength = min(leftStr.length(), rightStr.length());

        double partialScoreRate = 1- static_cast<double> (gap / minlength);
        return partialScoreRate * MAX_LENGTH_SCORE;
    }

    const double MAX_LENGTH_SCORE = 60;
};