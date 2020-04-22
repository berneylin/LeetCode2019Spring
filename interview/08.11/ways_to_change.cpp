class Solution {
public:
    int waysToChange(int n) {
        int coins[4] = {1, 5, 10, 25};
        long dp[n+1];
        for(int i=0; i<=n; i++) dp[i] = 0;
        const int MODE = 1e9+7;
        dp[0] = 1;
        for(int i=0; i<4; i++){
            for(int j=coins[i]; j<=n; j++){
                dp[j] = (dp[j]+dp[j-coins[i]])%MODE;
            }
        }
        return dp[n];
    }
};