#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    int moveArr[4][2] = {
        {-1, -1}, {-1, 1}
    };

    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard(n, string(n, '.'));
        vector<vector<string> > ansVec;
        dfs(chessboard, n, 0, ansVec);
        return ansVec;
    }

    void dfs(vector<string> &chessboard, int &n, int lineIdx, vector<vector<string> > &ansVec) {
        if(lineIdx==n){
            ansVec.push_back(chessboard);
        }

        for(int colIdx=0; colIdx<n; colIdx++){
            // 先扫描列方向
            bool existFlag = false;
            for(int i=0; i<n; i++){
                if(chessboard[i][colIdx]=='Q'){
                    existFlag = true; 
                    break;
                }
            }    
            if (existFlag) {
                continue; // 该列已经有皇后了，不能摆
            }        

            //继续扫描对角线方向(只要往左上和右上2个方向扫描即可)
            for (int moveIdx=0; moveIdx<2; moveIdx++) {
                int i = lineIdx + moveArr[moveIdx][0];
                int j = colIdx + moveArr[moveIdx][1];

                while(i<n && i>=0 && j<n && j>=0){
                    if(chessboard[i][j]=='Q'){
                        existFlag = true;
                        break;
                    }
                    i += moveArr[moveIdx][0];
                    j += moveArr[moveIdx][1];
                }

                if(existFlag) break;
            }

            if(existFlag) {
                continue;
            }
            // dfs
            chessboard[lineIdx][colIdx] = 'Q';
            dfs(chessboard, n, lineIdx+1, ansVec);
            chessboard[lineIdx][colIdx] = '.';
        }
    }
};