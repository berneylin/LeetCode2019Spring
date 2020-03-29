#include<vector>
#include<cstdlib>
using namespace std;

class Solution {
public:
    vector<int> mNums;

    Solution(vector<int>& nums) {
        mNums = nums;
    }
    
    int pick(int target) {
        int thisCnt = 0;
        for(const auto &num: mNums) {
            if(num==target) thisCnt++;
        }

        int idx = rand() % thisCnt;

        for(int i=0; i<mNums.size(); i++){
            if(mNums[i]==target){
                if(idx){
                    idx--;
                }else{
                    idx = i;
                    break;
                }
            }
        }
        return idx;
    }
};

// 流水采样法
class Solution {
public:
    vector<int> mNums;

    Solution(vector<int>& nums) {
        mNums = nums;
    }
    
    int pick(int target) {
        int thisCnt = 0, idx = 0;
        for(int i=0; i<mNums.size(); i++){
            if(mNums[i]==target){
                thisCnt ++;
                if(rand() % thisCnt == 0) 
                    idx = i; // 第一次一定会丢弃
            }
        }
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */