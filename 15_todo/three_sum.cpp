class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int numsLength = nums.size();
        vector<vector<int>> ret;
        if(numsLength<3) return ret;
        for(int i=0;i<numsLength-2;i++){
            int tmpSum = nums[i]+nums[i+1];
            for(int j=i+2;j<numsLength-1;j++){
                if(nums[j]==(-tmpSum)){
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[i+1]);
                    tmp.push_back(nums[j]);
                    ret.push_back(tmp);
                }
            }
        }



    }
};