class Solution {
public:
    int fib(int n) {
        if (n < 2)
            return n;
        
        long dp[n];
        const long mod = 1e9+7;
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i < n; i++) {
            dp[i] = (dp[i-1] + dp[i-2]) % mod;
        }
        return (dp[n-1] + dp[n-2]) % mod;
    }
};