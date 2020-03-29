#include<vector>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int numsSize = nums.size();
        if(numsSize<=1) return numsSize;
        int dp[numsSize];
        int cnt[numsSize];
        int maxLen = 1;
        int ans = 0;

        for(int i=0; i<numsSize; i++) dp[i] = 1;
        for(int i=0; i<numsSize; i++) cnt[i] = 1;

        for(int i=1; i<numsSize; i++){
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i]){
                    if(dp[j]>=dp[i]) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }else if(dp[j]+1 == dp[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            if(dp[i]>maxLen) maxLen = dp[i];
        }
        for(int i=0; i<numsSize; i++){
            if(dp[i]==maxLen) ans += cnt[i];
        }
        return ans;
    }
};