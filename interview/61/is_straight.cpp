class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int numsSize = nums.size();
        if(numsSize!=5) return false;

        int numCnt[14] = {0};

        for(int num: nums){
            numCnt[num]++;
        }
        int sumDiff = 0, last = 0;
        for(int i=1; i<=13; i++){
            if(numCnt[i]>=2) return false;  // 对子直接出局
            // 0 or 1
            if(numCnt[i]==1){
                if(last==0){
                    last = i;
                }else{
                    sumDiff += (i-last-1);
                    last = i;
                }
            }
        }
        return numCnt[0]>=sumDiff;
    }
};