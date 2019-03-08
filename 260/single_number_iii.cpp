class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size()==2) return nums;
        vector<int> ans;
        int acc = 0;
        int numsSize = nums.size();
        for(int i=0;i<numsSize;i++){
            acc ^= nums[i];
        }
        /* acc为只出现一次的2个数的异或结果 */
        int accHighOnePos = findHighOnePos(acc);
        vector<int> tmpA, tmpB;
        for(int i=0;i<numsSize;i++){
            if((nums[i]>>accHighOnePos) &1) tmpB.push_back(nums[i]);
            else tmpA.push_back(nums[i]);
        }
        acc = 0;
        for(int i=0;i<tmpA.size();i++) acc^=tmpA[i];
        ans.push_back(acc);
        acc = 0;
        for(int i=0;i<tmpB.size();i++) acc^=tmpB[i];
        ans.push_back(acc);
        return ans;
    }

    int findHighOnePos(int x){
        int pos = -1, retPos = -1;
        while(x){
            pos++;
            if(x&1) retPos = pos;
            x>>=1;
        }
        return retPos;
    }
};

