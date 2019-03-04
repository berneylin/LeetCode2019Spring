class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int numsSize = nums.size();
        int i = 0;
        while(i<numsSize){
            if(nums[i]==nums[nums[i]-1]) i++;
            else{
                int tmp = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = tmp;
            }
        }
        vector<int> res;
        for(i=0;i<numsSize;i++){
            if(nums[i]!=i+1){
                res.push_back(i+1);
            }
        }
        return res;
    }
};