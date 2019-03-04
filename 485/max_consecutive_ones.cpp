class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int numsSize = nums.size();
        int thisOneCnt = 0;
        int maxOneCnt = -1;
        for(int i=0;i<numsSize;i++){
            if(nums[i]){
                thisOneCnt++;
            }else{
                maxOneCnt = thisOneCnt>maxOneCnt?thisOneCnt:maxOneCnt;
                thisOneCnt = 0;
            }
        }
        maxOneCnt = thisOneCnt>maxOneCnt?thisOneCnt:maxOneCnt;
        return maxOneCnt;
    }
};