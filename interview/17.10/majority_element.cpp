class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.empty()) return -1;
        int thisCnt = 0, thisNum = nums[0];
        for(const int &num: nums){
            if(thisCnt==0) 
                thisNum = num;
            if(thisNum==num){
                thisCnt++;
            }else{
                thisCnt--;
            }
        }
        if(thisCnt==0) return -1;
        // check 是否为众数
        thisCnt == 0;
        for(const int &num: nums){
            if(num==thisNum) thisCnt++;
        }
        return thisCnt>(nums.size()/2)?thisNum:-1;
    }
};