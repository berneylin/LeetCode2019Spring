#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.empty()) return nums;
        vector<int> ansVec(nums.size(), 1);
        int left = 1, right = 1;
        for(int i=0; i<nums.size(); i++)
        {
            ansVec[i] *= left;
            left *= nums[i];

            ansVec[nums.size()-1-i] *= right;
            right *= nums[nums.size()-1-i];
        }
        return ansVec;
    }
};