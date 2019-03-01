#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> elem;
        sort(nums.begin(), nums.end());
        dfs(ans, nums, elem, 0);
        return ans;
    }

    void dfs(vector<vector<int> > &ans, vector<int> &nums, vector<int> &elem, int index){
        ans.push_back(elem);
        for(int i=index;i<nums.size();i++){
            if(i==index||nums[i]!=nums[i-1]){
                elem.push_back(nums[i]);
                dfs(ans, nums, elem, i+1);
                elem.pop_back();
            }

        }


    }
};