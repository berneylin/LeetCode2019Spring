#include<vector>
using namespace std;


class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        const int MOD = 1e9+7;
        vector<int> dp(target+1, 0);
        for(int i=0; i<d; i++){
            if(i==0){
                // first time
                for(int j=1; j<=f && j<=target; j++) dp[j] = 1;
            }
            else{
                for(int j=target; j>=0; j--){
                    dp[j] = 0;
                    for(int d=1; d<=f && d<=j; d++){
                        dp[j] = (dp[j] + dp[j-d]) % MOD;
                    }
                }
            }
        }
        return dp[target] % MOD;   
    }
};