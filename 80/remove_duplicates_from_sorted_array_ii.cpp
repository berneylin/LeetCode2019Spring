class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int thisCnt = 0;
        int overCnt = 0;
        int replaceIdx = 0;
        int numsSize = nums.size();
        for(int i=0;i<numsSize;i++){
            if(thisCnt==2){
                if(nums[i]==nums[replaceIdx-1]) continue;
                else{
                    thisCnt=1;
                    nums[replaceIdx] = nums[i];
                    overCnt++;
                    replaceIdx++;
                }
            }else{
                if(thisCnt==0){
                    // 第一次的情况
                    nums[replaceIdx] = nums[i];
                    thisCnt++;
                    overCnt++;
                    replaceIdx++;
                }else{
                    // 还能再放一个
                    if(nums[i]==nums[replaceIdx-1]){
                        // 相同的
                        thisCnt++;
                        overCnt++;
                        nums[replaceIdx] = nums[i];
                        replaceIdx++;
                    }else{
                        // 不同的
                        thisCnt = 1;
                        nums[replaceIdx] = nums[i];
                        overCnt++;
                        replaceIdx++;
                    }
                }
            }
        }
        return overCnt;
    }
};