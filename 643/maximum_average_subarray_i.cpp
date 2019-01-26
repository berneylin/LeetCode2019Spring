class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(nums.size()==0||nums.size()<k) return 0.0;
        long maxSubSum = 0;
        for(int i=0;i<k;i++){  // initialize the subSum with the first k numbers
            maxSubSum += nums[i];
        }
        int numSubs = nums.size()-k+1;
        long thisSubSum = maxSubSum;

        for(int i=1;i<numSubs;i++){
            thisSubSum += nums[i+k-1];
            thisSubSum -= nums[i-1];
            if(thisSubSum>maxSubSum) maxSubSum = thisSubSum;
        }

        double retMean = (double)maxSubSum / (double)k;
        return retMean;
    }
};