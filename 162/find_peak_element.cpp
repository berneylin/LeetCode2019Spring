class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size()-1, mid;
        int  ret = 0;
        while(left<=right){
            mid = left + (right - left)/2;
            if(mid==left){
                ret = nums[left]>nums[right]?left:right;
                break;
            }
            else{
                if(nums[mid]<nums[mid+1]) left = mid;
                else if(nums[mid]>nums[mid+1]) right = mid;
            }
        }
        return ret;
    }
};