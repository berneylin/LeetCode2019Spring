#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;

        int dp[nums.size()][2];
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        
        for(int i=1; i<nums.size(); i++){
            if(i==1){
                // 边界处理
                dp[1][0] = nums[0];
                dp[1][1] = max(nums[0], nums[1]);
                continue;
            }
            // 这一天不抢
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            // 这一天抢钱
            dp[i][1] = nums[i] + max(dp[i-1][0], dp[i-2][1]);
        }

        return max(dp[nums.size()-1][1], dp[nums.size()-1][0]);

    }
};