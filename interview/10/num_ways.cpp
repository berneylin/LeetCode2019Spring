class Solution {
public:
    int numWays(int n) {
        if (n < 2)
            return 1;
        
        const int mod = 1e9+7;
        int lhs = 1, rhs = 2;
        for (int i = 2; i < n; i++){
            rhs += lhs;
            lhs = rhs - lhs;
            if (rhs > mod)
                rhs -= mod;
        }
        return rhs>mod?rhs-mod:rhs;
    }
};