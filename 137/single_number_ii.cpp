class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0, threesInverse = 0;
        int numsSize = nums.size();

        for(int i=0;i<numsSize;i++){
            int thisNum = nums[i];
            twos |= (ones ^ thisNum);  // 先统计进位的1
            ones ^= thisNum;  // 再计算只出现一次的1（不用考虑进位了）
            threesInverse = ~(ones & twos);  // 出现3次的逆
            ones &= threesInverse;
            twos &= threesInverse;
        }
        return ones;
    }
};