#include<string>
using namespace std;

class Solution {
public:
    bool check(string &s, int i, int j) {
        int tmpNum = (s[i]-'0') * 10 + (s[j]-'0');
        return tmpNum >= 10 && tmpNum <= 25;
    }

    int translateNum(int num) {
        string numStr = to_string(num);
        if (numStr.length() == 1) return 1;
        int dp[numStr.length()+1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = check(numStr, 0, 1)?2:1;
        for(int i=3; i<=numStr.length(); i++) {
            if(check(numStr, i-2, i-1)) {
                dp[i] = dp[i-1] + dp[i-2];
            }else{
                dp[i] = dp[i-1];
            }
        }
        return dp[numStr.length()];

    }
};