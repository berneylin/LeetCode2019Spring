#include<climits>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int numsLength = nums.size();
        int dp[numsLength];
        int currentSum = 0;
        dp[0] = nums[0];
        for(int i=1;i<numsLength;i++){
            currentSum += nums[i];
            dp[i] = dp[i-1]>currentSum?dp[i-1]:currentSum;
            if(currentSum<0)
                currentSum = 0;
        }
        return dp[numsLength-1];
    }
};