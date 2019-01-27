class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /* Dynamic programming equation: subSum[i] = max(subSum[i-1]+nums[i], nums[i]) */
        int maxSum = nums[0];
        int numsLength = nums.size();
        int currSum = nums[0];

        for(int i=1;i<numsLength;i++){
            currSum = currSum>0?currSum+nums[i]:nums[i];
            maxSum = maxSum>currSum?maxSum:currSum;
        }

        return maxSum;
    }
};