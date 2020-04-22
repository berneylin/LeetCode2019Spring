#include<string>
using namespace std;

class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size()!=B.size()) return false;
        string C = A+A;
        return C.find(B)!=C.npos;
    }
};