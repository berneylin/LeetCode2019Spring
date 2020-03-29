#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        vector<vector<int> > dp(len1+1, vector<int>(len2+1, 0));

        for(int i=1; i<len1+1; i++){
            // 初始化s2为空的情况
            dp[i][0] += dp[i-1][0] + (int)(s1[i-1]);
        }

        for(int j=1; j<len2+1; j++){
            // 初始化s1为空的情况
            dp[0][j] += dp[0][j-1] + (int)(s2[j-1]);
        }

        for(int i=1; i<len1+1; i++){
            for(int j=1; j<len2+1; j++){
                if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1];  // 当前2个结尾字母相同 不需要删除
                else{
                    int nextDP1 = dp[i][j-1] + (int)s2[j-1];  // 保留s1的当前字母，删掉s2当前字母
                    int nextDP2 = dp[i-1][j] + (int)s1[i-1];  // 保留s2的当前字母，删掉s1当前字母
                    dp[i][j] = nextDP1<nextDP2?nextDP1:nextDP2;
                }
            }
        }

        return dp[len1][len2];
    }
};