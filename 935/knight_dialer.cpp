class Solution {
public:
    int knightDialer(int N) {
        const int MODE = 1000000007;
        long dp[10];
        long tmp[10];
        tmp[5] = 1;
        for(int i=0;i<10;i++) dp[i] = 1;
        if(N==1) return 10;
        while(--N){
            tmp[0] = (dp[4] + dp[6]) % MODE;
            tmp[1] = (dp[6] + dp[8]) % MODE;
            tmp[2] = (dp[7] + dp[9]) % MODE;
            tmp[3] = (dp[4] + dp[8]) % MODE;
            tmp[4] = (dp[9] + dp[3] + dp[0]) % MODE;
            tmp[6] = (dp[1] + dp[7] + dp[0]) % MODE;
            tmp[7] = (dp[2] + dp[6]) % MODE;
            tmp[8] = (dp[1] + dp[3]) % MODE;
            tmp[9] = (dp[2] + dp[4]) % MODE;
            for(int i=0;i<10;i++) dp[i] = tmp[i] % MODE;
        }
        int sum = 0;
        for(int i=0;i<10;i++){
            if(i==5) continue;
            sum = (sum + dp[i]) % MODE;
        }
        return sum;
    }
};