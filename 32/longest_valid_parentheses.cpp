#include<cstring>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length()<=1) return 0;
        int dp[s.length()];
        memset(dp, 0, sizeof(int)*s.length());
        int ans = 0x80000000;

        for(int i=1; i<s.length(); i++){
            if(s[i]==')'){
                int preIdx = i-dp[i-1]-1;
                if(preIdx >=0 && s[preIdx]=='('){
                    dp[i] = dp[i-1] + 2;
                    if(preIdx>0){
                        dp[i] += dp[preIdx-1];
                    }
                }
            }
            ans = ans>dp[i]?ans:dp[i];
        }

        return ans;
    }
};