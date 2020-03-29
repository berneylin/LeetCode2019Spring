#include<vector>
#include<cstring>
using namespace std;


class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int numCnt[50000];
        int startIdx[50000];
        int endIdx[50000];
        memset(numCnt, 0, sizeof(int)*50000);
        memset(startIdx, 0, sizeof(int)*50000);
        memset(endIdx, 0, sizeof(int)*50000);

        for(int i=0; i<nums.size(); i++){
            if(numCnt[nums[i]]==0){
                startIdx[nums[i]] = i;
            }
            endIdx[nums[i]] = i;
            numCnt[nums[i]]++;
        }

        int degree = 0;
        for(int eachCnt: numCnt){
            if(eachCnt>degree) degree = eachCnt;
        }
        int ans = nums.size();
        for(int i=0; i<50000; i++){
            if(numCnt[i]==degree){
                if((endIdx[i]-startIdx[i]+1)<ans){
                    ans = endIdx[i]-startIdx[i]+1;
                }
            }
        }
        return ans;
    }
};