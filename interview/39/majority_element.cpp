#include<vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorNum = nums[0], majorCnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (majorCnt == 0) {
                majorNum = nums[i];
                majorCnt ++;
            } else {
                if (majorNum == nums[i]) {
                    majorCnt ++;
                } else {
                    majorCnt --;
                }
            }
        }
        return majorNum;
    }
};