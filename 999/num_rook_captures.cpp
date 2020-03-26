#include<vector>
using namespace std;


class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0)
            return 0;
        const int BOARD_LEN = 8;
        int ri = 0, rj = 0, findFlag = 0;
        for (int i = 0; i < BOARD_LEN; ++i) {
            for (int j = 0; j < BOARD_LEN; ++j) {
                if(board[i][j] == 'R') {
                    ri = i;
                    rj = j;
                    findFlag = 1;
                    break;
                }
            }
            if (findFlag) {
                break;
            }
        }

        int rtnCnt = 0;
        int moveArr[4][2] = {
            {1,0}, {-1,0}, {0, 1}, {0, -1}
        };

        for (int moveIdx = 0; moveIdx < 4; moveIdx++) {
            int thisI = ri, thisJ = rj;
            thisI += moveArr[moveIdx][0];
            thisJ += moveArr[moveIdx][1];
            while(thisI < BOARD_LEN && thisI >= 0 && thisJ < BOARD_LEN && thisJ >= 0) {
                if(board[thisI][thisJ]=='p') {
                    rtnCnt++;
                }
                if(board[thisI][thisJ]!='.') {
                    break;
                }
                thisI += moveArr[moveIdx][0];
                thisJ += moveArr[moveIdx][1];
            }
        }
        return rtnCnt;
    }
};