#include <string>
#include <cstring>
#include <vector>
using namespace std;


class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int chessboard[3][3];
        int i = 0;
        memset(chessboard, 0, sizeof(chessboard));
        for (i=0; i<moves.size(); i++) {
            vector<int> &tmpVec = moves[i];
            chessboard[tmpVec[0]][tmpVec[1]] = i%2?'x':'o';
            // attempt to judge winner
            bool finishFlag = false;
            finishFlag |= chessboard[tmpVec[0]][0] != 0 && chessboard[tmpVec[0]][0] == chessboard[tmpVec[0]][1] && chessboard[tmpVec[0]][0] == chessboard[tmpVec[0]][2];
            finishFlag |= chessboard[0][tmpVec[1]] != 0 && chessboard[0][tmpVec[1]] == chessboard[1][tmpVec[1]] && chessboard[0][tmpVec[1]] == chessboard[2][tmpVec[1]];
            finishFlag |= chessboard[0][0] != 0 && chessboard[0][0] == chessboard[1][1] && chessboard[0][0] == chessboard[2][2];
            finishFlag |= chessboard[0][2] != 0 && chessboard[0][2] == chessboard[1][1] && chessboard[0][2] == chessboard[2][0];
            if (finishFlag) {
                return i%2==0?"A":"B";
            }
        }
        if(i==9) return "Draw";
        else return "Pending";
    }
};