class Solution {
public:
    void partition(vector<int> &nums, int lhs, int rhs, const int &K){
        if(lhs>=rhs) return;
        int pivot = nums[lhs];
        int l = lhs, r = rhs;

        while(l<r){
            while(l<r && nums[r]<=pivot) r--;
            while(l<r && nums[l]>=pivot) l++;
            if(l<r){
                int tmp = nums[l];
                nums[l] = nums[r];
                nums[r] = tmp;
            }
        }

        nums[lhs] = nums[l];
        nums[l] = pivot;

        if (l==K) return;
        else if(l<K) partition(nums, l+1, rhs, K);
        else if(l>K) partition(nums, lhs, l-1, K);
    }


    int findKthLargest(vector<int>& nums, int k) {
        if(k>nums.size() || k<=0) return 0;
        partition(nums, 0, nums.size()-1, k-1);
        return nums[k-1];
    }
};