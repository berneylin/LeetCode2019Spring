class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bitSum[32] = {0};
        int mask = 1;
        for(int i=0; i<32; i++) {
            for(int num: nums){
                if(num&mask){
                    bitSum[i]++;
                }
            }
            if(i!=31)
                mask <<= 1;
        }
        int base = 1, ans = 0;
        for(int i=0; i<32; i++) {
            ans += base * (bitSum[i] % 3);
            if(i!=31)
                base <<= 1;
        }
        return ans;
    }
};