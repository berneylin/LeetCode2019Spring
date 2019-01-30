#include<vector>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

class Solution {
public:
    void swap(vector<int> &nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int numsSize = nums.size();
        vector<vector<int> > ans;
        bool isUsed[numsSize];
        memset(isUsed, 0, sizeof(bool)*numsSize);
        vector<int> elem;
        dfs(ans, isUsed, elem, nums);
        return ans;
    }

    void dfs(vector<vector<int> > &ans, bool* isUsed, vector<int> &elem, vector<int> &nums){
        if(elem.size()==nums.size()){
            ans.push_back(elem);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(isUsed[i]) continue;
            if(i>0 && nums[i]==nums[i-1]&&!isUsed[i-1]) continue;
            isUsed[i] = true;
            elem.push_back(nums[i]);
            dfs(ans, isUsed, elem, nums);
            elem.pop_back();
            isUsed[i] = false;
        }

    }
};

int main(void){
    Solution *sol = new Solution();
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(9);
    vector<vector<int> > ans = sol->permuteUnique(nums);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}