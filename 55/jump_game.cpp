class Solution {
public:
    bool canJump(vector<int>& nums) {
        int upper = 0;
        int i = 0;
        int numsSize = nums.size();
        while(i<numsSize && i<=upper){
            upper = upper>(i+nums[i])?upper:(i+nums[i]);
            i++;
        }
        return upper>=numsSize-1;
    }
};