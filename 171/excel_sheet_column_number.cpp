#include<string>
using namespace std;

class Solution {
public:
    inline int charToNum(char ch){
        return (int)(ch - 'A' + 1);
    }

    int titleToNumber(string s) {
        long ans = 0;
        long weight = 1;
        for(string::reverse_iterator rit=s.rbegin(); rit!=s.rend(); rit++){
            ans += weight * charToNum(*rit);
            weight *= 26;
        }
        return (int)ans;
    }
};