#include<vector>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.empty()) return 0;
        int thisMin = nums[0];
        for(const int &num: nums){
            if (num<thisMin){
                thisMin = num;
            }
        }
        int overallCnt = 0;
        for(const int &num: nums){
            overallCnt += (num-thisMin);
        }
        return overallCnt;
    }
};