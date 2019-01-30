#include<vector>
#include<cstring>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > ans;
        int numsSize = nums.size();
        bool isUsed[numsSize];
        memset(isUsed, 0, sizeof(bool)*numsSize);
        vector<int> toBeDicided;
        dfs(ans, nums, numsSize, isUsed, toBeDicided);
        return ans;
    }

    void dfs(vector<vector<int> > &ans, vector<int> &nums, int numsSize, bool* isUsed, vector<int> &toBeDicided){
        if(toBeDicided.size()==numsSize) ans.push_back(toBeDicided);
        else{
            for(int i=0;i<numsSize;i++){
                if(isUsed[i]) continue;
                else{
                    toBeDicided.push_back(nums[i]);
                    isUsed[i] = true;
                    dfs(ans, nums, numsSize, isUsed, toBeDicided);
                    isUsed[i] = false;
                    toBeDicided.pop_back();
                }
            }
        }
        
    }
};