class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int numsSize = nums.size();

        for(int i=0;i<numsSize;i++){
            
            if(nums[i]<=0 || nums[i]>numsSize) continue;
            if(nums[nums[i]-1] != nums[i]){  // 关心的数没有放在正确的位置（nums[i]-1)上
                int tmp = nums[i];
                nums[i] = nums[nums[i]-1];
                nums[tmp-1] = tmp;
                i--;  // 原地再次判断 防止漏数
            }
        }

        for(int i=0;i<numsSize;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return numsSize+1;
    }
};