class Solution {
public:
    int rob(vector<int>& nums) {
        int numsSize = nums.size();
        if(!numsSize) return 0;
        else if(numsSize==1) return nums[0];
        else if(numsSize==2) return nums[0]>nums[1]?nums[0]:nums[1];
        int dp[numsSize] = {nums[0], nums[1]};
        int beforeMax = nums[0];
        for(int i=2;i<numsSize;i++){
            int tmp = beforeMax + nums[i];
            beforeMax = beforeMax>dp[i-1]?beforeMax:dp[i-1];
            dp[i] = tmp>dp[i-1]?tmp:dp[i-1];
        }
        return dp[numsSize-1];
    }
};