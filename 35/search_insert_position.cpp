class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size(), mid;
        while(left<right){
            mid = left + (right-left)>>1;
            if(nums[mid]==target) return mid;
            else if (nums[mid]<target) left = mid;
            else right = mid+1;
        }
        return left;
    }
};