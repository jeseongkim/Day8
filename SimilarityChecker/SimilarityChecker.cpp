#include <stdexcept>
#include<iostream>
#include<cmath>
using namespace std;

class SimilarityChecker {
public:
    double getLengthResult(const string leftStr, const string rightStr) {
        if (isZeroLengthArgs(leftStr, rightStr)) return 0;

        if (leftStr.length() == rightStr.length()) return MAX_LENGTH_SCORE;

        return MAX_LENGTH_SCORE * getPartialLengthScore(leftStr, rightStr);
    }

    double getAlphaResult(const string leftStr, const string rightStr){
        for(auto ch : leftStr){
            if(ch < 'A' || ch > 'Z') return 0;
        }
        for(auto ch : rightStr){
            if(ch < 'A' || ch > 'Z') return 0;
        }
    }

private:
    double getPartialLengthScore(const string leftStr, const string rightStr) {
        double gap = abs( static_cast<int>(leftStr.length() - rightStr.length()) );
        double minlength = min(leftStr.length(), rightStr.length());

        return getPartialScore(gap, minlength);
    }
 
    double getPartialScore(double gap, double minlength){
        return 1 - (gap / minlength);
    }

    bool isZeroLengthArgs(const string leftStr, const string rightStr) {
        if (leftStr.length() == 0) return true;
        if (rightStr.length() == 0) return true;
        return false;
    }
    const double MAX_LENGTH_SCORE = 60;
};