class Solution {
public:
    int hammingWeight(uint32_t n) {
        int mask = 1<<31, cnt = 0;
        // mask: 10000...000
        cnt += n&mask?1:0;
        // mask: 01111...111
        mask = ~mask;
        n &= mask;
        while(n){
            cnt += n&1;
            n >>= 1;
        }
        return cnt;
    }
};