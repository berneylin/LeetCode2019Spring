#include<vector>
#include<cstring>
using namespace std;


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.empty()) return false;
        long total = 0;
        for(const auto &num: nums) total += num;
        if(total & 1) return false;
        long target = total>>1;

        int dp[nums.size()][target+1];
        memset(dp, 0, sizeof(int)*nums.size()*(target+1));

        if (nums[0]<=target) dp[0][nums[0]] = true;
        for(int i=1; i<nums.size(); i++){
            for(int j=0; j<target; j++){
                if(nums[i]==j) {
                    dp[i][j] = true;
                }
                else if(nums[i]<j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
                
            }
        }

        return dp[nums.size()-1][target];
    }
};