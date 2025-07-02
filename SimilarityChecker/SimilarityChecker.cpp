#include <stdexcept>
#include<iostream>
using namespace std;

class SimilarityChecker {
public:
    int getLengthResult(const string leftStr, const string rightStr) {
        if (leftStr.size() == rightStr.size()) return 60;
        return 0;
    }
};