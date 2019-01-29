class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret;
        int leftProduct = 1;  // initialize with one
        int numsSize = nums.size();
        for(int i=0;i<numsSize;i++){
            ret.push_back(leftProduct);
            leftProduct*=nums[i];
        }
        int rightProduct = 1;  // initialize with one
        for(int i=numsSize-1;i>=0;i--){
            ret[i] *= rightProduct;
            rightProduct *= nums[i];
        }
        return ret;
    }
};