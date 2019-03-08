#include<algorithm>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int numsSize = nums.size();
        int maxHarSeqLen = 0;
        sort(nums.begin(), nums.end());

        int i = 0;
        while(i<numsSize){
            if(i<numsSize-1 && nums[i+1]-nums[i]==1){
                int l = i;
                int r = i+1;
                while(l>=0&&nums[l]==nums[i]) l--;
                while(r<numsSize && nums[r]==nums[i+1]) r++;
                maxHarSeqLen = (r-l-1)>maxHarSeqLen?(r-l-1):maxHarSeqLen;
            }
            i++;
        }
        
        return maxHarSeqLen;
    }
};