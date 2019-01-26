class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = ((n & 0x80000000)?1:0);  // add the highest bit
        n = n & 0x7FFFFFFF; // remove the highest bit to ultilize `>>' logical operator
        while(n){
            cnt += (n&1);
            n>>=1;
        }

        return n;
    }
};