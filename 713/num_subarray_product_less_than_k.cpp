#include<vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        if(k==0 || k==1) return 0;
        int l = 0, r = 0, ansCnt = 0;
        long thisProduct = 1;

        while(r<nums.size()){
            thisProduct *= nums[r];
            while(thisProduct>=k){
                thisProduct /= nums[l];
                l++;
            }
            ansCnt += r-l+1;
            r++;
        }
        return ansCnt;
    }
};