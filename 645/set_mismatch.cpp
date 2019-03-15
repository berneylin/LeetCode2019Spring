class Solution {
public:
    inline int abs(int x){
        return x>=0?x:-x;
    }
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        const int NUMSSIZE = nums.size();
        for(int i=0;i<NUMSSIZE;i++){
            nums[abs(nums[i])-1] *= -1;
        }
        for(int i=0;i<NUMSSIZE;i++){
            if(nums[i]>0) ans.push_back(i+1);
        }
        for(int i=0;i<NUMSSIZE;i++){
            if(abs(nums[i])==ans[0]) break;
            if(i==NUMSSIZE-1){
                int tmp = ans[0];
                ans[0] = ans[1];
                ans[1] = tmp;
            }
        }
        return ans;
    }
};