#include<vector>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int numsLength = nums.size();
        int ans = 0;
        for (int i = 0; i < numsLength; i++)
        {
            int targetIdx = nums[i];
            if (i != nums[i] && nums[targetIdx] == nums[i])
            {
                ans = targetIdx;
                break;
            }            
            int tmpNum = nums[i];
            nums[i] = nums[targetIdx];
            nums[targetIdx] = tmpNum;
        }
        return ans;
    }
};