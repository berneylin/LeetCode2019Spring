class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        dp[0] = 0;
        for(int i=1;i<=n;i++) dp[i] = 0x7FFFFFFF;
        for(int i=1;i<=n;i++){
            for(int k=1;k*k<=i;k++){
                dp[i] = dp[i]<(dp[i-k*k]+1)?dp[i]:dp[i-k*k]+1;
            }
        }
        return dp[n];
    }
};