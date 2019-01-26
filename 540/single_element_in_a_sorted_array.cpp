class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ret = 0;
        int cnt = 0;
        int sizeNums = nums.size();

        if(sizeNums==1) return nums[0];  // only one element in the array, must be unique
        
        int i=0, j=1, k=2; // triple tuple
        while(k<sizeNums){
            if(nums[i]!=nums[j]&&nums[j]!=nums[k]){
                ret = nums[j];
                break;
            }else{
                i++;j++;k++;
            }
        }
        if(nums[sizeNums-1]!=nums[sizeNums-2]) ret = nums[sizeNums-1];  // boundary condition
        return ret;
    }
};