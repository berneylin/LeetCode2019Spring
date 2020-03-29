#include<vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        int l = 0, r = 1, ans = 0;
        // [1,3,5,4,7]
        while(l < r && r < nums.size()){
            if(nums[r]<=nums[r-1]){
                //更新答案及窗口
                if((r-l)>ans) ans = r-l;
                l=r;
            }
            r++;
        }

        if((r-l)>ans) ans = r-l;
        return ans;

    }
};