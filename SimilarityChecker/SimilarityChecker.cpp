#include <stdexcept>
#include<iostream>
using namespace std;

class SimilarityChecker {
public:
    int getLengthResult(string a, string b) {
        if (a.size() == b.size()) return 60;
        return 0;
    }
};