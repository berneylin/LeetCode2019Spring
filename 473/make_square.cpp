#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a, int b){
    return a>b;
}


bool cmp(int a, int b){
    return a>b;
}


class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size()<4) return false;
        long totalLen = 0;
        for(const auto &num: nums) totalLen += num;

        if(totalLen%4) return false;
        
        long oneLen = totalLen / 4;
        sort(nums.begin(), nums.end(), cmp);
        if(nums[0]>oneLen) return false;

        vector<long> bucket(4, oneLen);

        return dfs(nums, bucket, 0);
    }

    bool dfs(vector<int> &nums, vector<long> &bucket, int idx){
        if(idx==nums.size()) {
            return bucket[0] == 0 && bucket[1] == 0 && bucket[2] == 0 && bucket[3] == 0;
        }
        for(int j=0; j<4; j++){
            if(bucket[j]<nums[idx]) continue;
            bucket[j] -= nums[idx];
            if(dfs(nums, bucket, idx+1)) return true;
            bucket[j] += nums[idx];
        }
        return false;
    }
};