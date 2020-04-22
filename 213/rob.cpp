#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int numsSize = nums.size();
        if(numsSize==0) return 0;
        if(numsSize==1) return nums[0];

        int dp[numsSize][2];
        // 第一次 抢第一家
        dp[0][0] = 0;
        dp[0][1] = nums[0];

        for(int i=1; i<numsSize-1; i++){
            if(i==1){
                dp[1][0] = nums[0];
                dp[1][1] = nums[1];
                continue;
            }
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = max(dp[i-1][0], dp[i-2][1]) + nums[i];
        }
        int firstMax = max(dp[numsSize-2][0], dp[numsSize-2][1]);


        // 第二次 抢最后一家
        dp[1][0] = 0;
        dp[1][1] = nums[1];

        for(int i=2; i<numsSize; i++){
            if(i==2){
                dp[2][0] = nums[1];
                dp[2][1] = nums[2];
                continue;
            }
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = max(dp[i-1][0], dp[i-2][1]) + nums[i];
        }
        int secondMax = max(dp[numsSize-1][0], dp[numsSize-1][1]);
        return max(firstMax, secondMax);
    }
};