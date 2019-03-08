class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if(k==0) return;
        reverseArray(nums, 0, nums.size()-1);
        reverseArray(nums, 0, k-1);
        reverseArray(nums, k, nums.size()-1);
    }

    void reverseArray(vector<int>& nums, int startIdx, int endIdx) {
        int midIdx = startIdx + (endIdx - startIdx)/2;
        for(int i=0;startIdx+i<=midIdx;i++) {
            int tmp = nums[startIdx+i];
            nums[startIdx+i] = nums[endIdx-i];
            nums[endIdx-i] = tmp;
        }
    }
};