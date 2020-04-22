class Solution {
public:
    inline int min(int x, int y){
        return x<y?x:y;
    }
    int getKthMagicNumber(int k) {
        int dp[k];
        dp[0] = 1;
        int i3 = 0, i5 = 0, i7 = 0;
        for(int i=1; i<k; i++){
            int tmp = min(min(dp[i3]*3, dp[i5]*5), dp[i7]*7);
            if(tmp==dp[i3]*3) i3++;
            if(tmp==dp[i5]*5) i5++;
            if(tmp==dp[i7]*7) i7++;
            dp[i] = tmp;
        }
        return dp[k-1];
    }
};