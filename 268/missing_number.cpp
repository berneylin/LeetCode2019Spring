class Solution {
public:
    inline int abs(int x) {
        return x>=0?x:-x;
    }
    int missingNumber(vector<int>& nums) {
        bool zeroFlag = false;
        int numsSize = nums.size();
        for(int i=0;i<numsSize;i++){
            if(nums[i]==0) zeroFlag = true;  // 记录0已经出现过
            else{
                nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
            }
        }
        if(!zeroFlag) return 0;
        int i = 0, zeroPos = 0;
        for(;i<numsSize;i++){
            if(nums[i]==0) zeroPos = i;
            else if(nums[i]>0) return i+1;
        }
        return zeroPos+1;
    }
};