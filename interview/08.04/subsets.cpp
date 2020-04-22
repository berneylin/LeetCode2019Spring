#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ansVec;
        vector<int> tmpVec;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, tmpVec, ansVec);
        return ansVec;
    }

    void dfs(vector<vector<int> > &nums, int startIdx, vector<int> &tmpVec, vector<vector<int> > &ansVec){
        ansVec.push_back(tmpVec);
        for(int i=startIdx; i<nums.size(); i++){
            if(i>startIdx && nums[i-1]==nums[i]) continue;
            tmpVec.push_back(nums[i]);
            dfs(nums, i+1, tmpVec, ansVec);
            tmpVec.pop_back();
        }
    }
};