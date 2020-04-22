#include<vector>
#include<string>
#include<algorithm>
using namespace std;


class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int strsSize = strs.size();
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        for(int i=0; i<strsSize; i++){
            int zeroCnt = 0, oneCnt = 0;
            for(const char &ch: strs[i]){
                if(ch=='0') zeroCnt++;
                else oneCnt++;
            }
            for(int mIdx=m; mIdx>=zeroCnt; mIdx--){
                for(int nIdx=n; nIdx>=oneCnt; nIdx--){
                    dp[mIdx][nIdx] = max(dp[mIdx][nIdx], dp[mIdx-zeroCnt][nIdx-oneCnt]+1);
                }
            }
        }
        return dp[m][n];
    }
};