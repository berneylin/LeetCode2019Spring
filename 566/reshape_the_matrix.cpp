#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<vector<int>> ret;
        int numsRawR = nums.size(), numsRawC;
        if(!numsRawR) return ret;
        else numsRawC = nums[0].size();

        if(r*c != numsRawC*numsRawR) return nums;  // illegal target shape, return original matrix
        int thisCol = 0, thisRow = 0;

        for(int i=0;i<numsRawR;i++){
            for(int j=0;j<numsRawC;j++){
                int thisNum = nums[i][j];
                if(thisCol==0){
                    vector<int> tmp;
                    ret.push_back(tmp);
                }
                ret[thisRow].push_back(thisNum);
                thisCol++;
                if(thisCol>=c) {
                    thisCol = 0;
                    thisRow ++;
                }
            }
        }
        return ret;
    }
};