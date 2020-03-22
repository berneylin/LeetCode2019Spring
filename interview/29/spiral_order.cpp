#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int rowNum = matrix.size();
        if (rowNum == 0) {
            return ret;
        }
        int colNum = matrix[0].size();
        if (colNum == 0) {
            return ret;
        }

        int mod[4][2] = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };

        int i = 0, j = 0, cnt = rowNum * colNum, modIdx = 0;
        int rowH = 0, rowL = rowNum, colL = 0, colR = colNum;
        while(cnt--){
            ret.push_back(matrix[i][j]);
            int nextI = i + mod[modIdx][0];
            int nextJ = j + mod[modIdx][1];
            if (nextI < rowH || nextI >= rowL || nextJ < colL || nextJ >= colR) {
                if (modIdx == 0) rowH ++;
                else if (modIdx == 1) colR --;
                else if (modIdx == 2) rowL --;
                else colL ++;
                modIdx = (modIdx + 1) % 4;
            }
            i += mod[modIdx][0];
            j += mod[modIdx][1];
        }
        return ret;
    }
};