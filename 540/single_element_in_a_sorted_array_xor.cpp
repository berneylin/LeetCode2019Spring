class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ret = 0;
        int sizeNums = nums.size();
        if(sizeNums){
            for(int i=0;i<sizeNums;i++){
                ret ^= nums[i];
            }
        }
        return ret;
    }
};