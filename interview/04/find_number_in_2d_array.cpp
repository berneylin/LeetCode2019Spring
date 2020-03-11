#include<vector>

using namespace std;


class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int rowNum = matrix.size();
        if(rowNum == 0)
            return false;
        int colNum = matrix[0].size();
        int i = 0, j = colNum - 1, thisNum = 0;
        while(i < rowNum && j >= 0) {
            thisNum = matrix[i][j];
            if (thisNum == target)
                return true;
            else if (thisNum > target) j--;
            else i++;
        }
        return false;
    }
};