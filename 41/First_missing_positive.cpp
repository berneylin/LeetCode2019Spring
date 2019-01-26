class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for(int i=0;i<len;i++){
            int currNum = nums[i];
            int nextPos = currNum - 1;
            if(nextPos<0||nextPos>=len) continue; // illegal position
            else if(nextPos==i) continue; // already correct position
            else if(nums[nextPos]==currNum) continue; // overlap correct position number
            else{
                nums[i] = nums[nextPos];
                nums[nextPos] = currNum;
                i--;
            }
        }
        int ret = 1;
        for(int i=0;i<len;i++){
            if(nums[i]!=i+1){
                ret = i+1;
                break;
            }
            if(i==len-1) ret=len+1;
        }
        return ret;
    }
};