class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;
        int numsSize = nums.size(), ans = 1, thisLen = 1;

        for(int i=1;i<numsSize;i++){
            if(nums[i]>nums[i-1]) thisLen++;
            else{
                ans = ans>thisLen?ans:thisLen;
                thisLen = 1;
            }
        }
        ans = ans>thisLen?ans:thisLen;
        return ans;
    }
};