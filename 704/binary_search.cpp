class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int NUMSSIZE = nums.size();
        int l = 0, r = NUMSSIZE-1, m;
        while(l<=r){
            m = l + (r-l)>>1;
            if(nums[m]==target) return m;
            else if(nums[m]<target) l = m+1;
            else if(nums[m]>target) r = m-1;
        }
        return -1;
    }
};