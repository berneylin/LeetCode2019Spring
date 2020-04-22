#include<vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = -1;
        for(int i=0; i<nums.size(); i++){
            int currentNum = nums[i];
            int currentIdx = nums[i]<0?-(nums[i]+1):nums[i]-1;
            if(nums[currentIdx]<0) {
                ans = currentNum<0?-currentNum:currentNum;
                break;
            }else{
                nums[currentIdx] *= -1;
            }
        }
        return ans;
    }
};