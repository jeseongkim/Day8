#include <stdexcept>
#include<iostream>
#include<cmath>
using namespace std;

class SimilarityChecker {
public:
    double getLengthResult(const string leftStr, const string rightStr) {
        if (leftStr.length() == rightStr.length()) return 60;

        int llength = leftStr.length();
        int rlength = rightStr.length();
        double gap = abs(llength - rlength);
        double minlength = min(leftStr.length(), rightStr.length());
        double result = gap / minlength;
        result = 1 - result;
        result *= 60;

        return result;
    }
};