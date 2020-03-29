#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        // 1. 如果nums的和不能被k整除 一定不能划分
        int sum = 0;
        for(int eachNum: nums) sum += eachNum;
        if(sum%k) return false;

        // 2. k个子集中，每个和都为 sum/k
        int target = sum/k;
        int thisTarget = target;
          

        // 3. 对nums降序排序，先取大的数字
        sort(nums.begin(), nums.end(), greater<int>());
        vector<bool> used(nums.size(), false);
        if(nums[0]>target) return false;  // 如果有比target还要大的数，那肯定没法分
        
        // 4. 开始判断
        vector<int> bucket(k, target);
        return dfs(k, 0, nums, bucket);
       
    }

    bool dfs(int k, int numIdx, vector<int> &nums, vector<int> &bucket){
        if(numIdx==nums.size()) return true;
        for(int i=0; i<k; i++){
            if(bucket[i]==nums[numIdx] || bucket[i]-nums[numIdx]>=nums[nums.size()-1]){
                bucket[i] -= nums[numIdx];
                if(dfs(k, numIdx+1, nums, bucket)) return true;
                bucket[i] += nums[numIdx];
            }
        }
        return false;
    }
};