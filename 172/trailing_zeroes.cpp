class Solution {
public:
    int trailingZeroes(int n) {
        if(n<5) return 0;
        int cnt = 0;
        while(n){
            cnt += n/5;
            n /= 5;
        }
        return cnt;
    }
};