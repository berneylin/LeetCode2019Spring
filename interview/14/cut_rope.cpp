class Solution {
public:
    int cuttingRope(int n) {
        long mod = 1e9+7;
        if (n==2) return 1;
        if (n==3) return 2;
        long ans = 1;
        while(n>4){
            ans *= 3;
            n -= 3;
            ans %= mod;
        }
        ans *= n;
        return ans % mod;
    }
};