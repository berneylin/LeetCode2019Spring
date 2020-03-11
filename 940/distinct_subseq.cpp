class Solution {
public:
    int distinctSubseqII(string S) {
        long mod = 1e9+7;
        long dp[26];
        memset(dp, 0, 26 * sizeof(long));
        long arrSum  = 0;
        for (int i = 0; i < S.length(); i++){
            int arrIdx = S[i] - 'a';
            long oldNum = dp[arrIdx];
            dp[arrIdx] = (arrSum + 1) % mod;
            arrSum = (arrSum - oldNum + dp[arrIdx] + mod) % mod;
        }
        return arrSum;
    }
};