#include<vector>
using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tmpVec;
        for(int i=0; i<nums.size(); i++){
            // 初始情况
            if(i==0) tmpVec.push_back(nums[i]);
            else{
                // 二分查找寻找上界(找第一个比当前数大于等于的)
                int l = 0, r = tmpVec.size();
                while(l<r){
                    int m = l + ((r-l)>>1);
                    if(tmpVec[m]<nums[i]) l = m+1;
                    else r = m;
                }
                if(l<tmpVec.size()) tmpVec[l] = nums[i];
                else tmpVec.push_back(nums[i]);
            }
        }
        return tmpVec.size();
    }
};