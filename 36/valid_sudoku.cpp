#include<unordered_map>
using namespace std;



class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> boxMap[9];
        unordered_map<char, int> rowMap[9];
        unordered_map<char, int> colMap[9];

        for(int i=0;i<9;i++){
            auto rawPair = make_pair<char, int>('0'+1+i, 0);
            for(int j=0;j<9;j++){
                boxMap[j].insert(rawPair);
                rowMap[j].insert(rawPair);
                colMap[j].insert(rawPair);
            }
        }

        bool ret = true;
        for(int i=0;ret&&i<9;i++){
            for(int j=0;ret&&j<9;j++){
                if(board[i][j]=='.') continue;
                int thisBoxIdx = 3*(j/3)+i/3;
                char thisChar = board[i][j];
                ret = !(boxMap[thisBoxIdx][thisChar]++ || rowMap[i][thisChar]++ || colMap[j][thisChar]++);
            }
        }
        return ret;
    }
};