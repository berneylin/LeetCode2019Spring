class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool ans = true;
        while(ans&&n){
            ans = ((n^(n>>1))&1;
            n>>=1;
        }
        return ans;
    }
};