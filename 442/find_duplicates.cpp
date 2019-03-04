class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int numsSize = nums.size();
        int i = 0;
        while(i<numsSize){
            if(nums[i]!=nums[nums[i]-1]){
                int tmp = nums[i];
                nums[i] = nums[nums[i]-1];
                nums[nums[i]-1] = tmp;
            }else{
                i++;
            }
        }
        vector<int> res;
        for(i=0;i<numsSize;i++){
            if(nums[i]!=i+1) res.push_back(nums[i]);
        }
        return res;
    }
};