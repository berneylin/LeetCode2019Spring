#include<string>
#include<vector>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;


class Solution {
public:
    vector<string> emptyChessBoard;
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ret;
        // construct empty n*n chessboard 
        string emptyLine = "";
        for(int i=0;i<n;i++) emptyLine+=".";
        for(int i=0;i<n;i++) emptyChessBoard.push_back(emptyLine);
        vector<int*> indexList;
        dfs(ret, indexList, 0, n);
        return ret;
    }

    void dfs(vector<vector<string> > &ret, vector<int*> &indexList, int chessCnt, int target){
        int i = chessCnt;
        for(int j=0;j<target;j++){
            bool legalFlag = true;
            for(int k=0;k<chessCnt;k++){
                if(indexList[k][0]==i||indexList[k][1]==j||abs(i-indexList[k][0])==abs(j-indexList[k][1])){
                    legalFlag=false;
                    break;
                }
            }
            if(legalFlag){  // currently satisfy legal condition check, continue dfs
                int tmp[2];
                tmp[0] = i;
                tmp[1] = j;
                indexList.push_back(tmp);
                if(chessCnt+1==target){
                    // satisfy number condition, generate string chessboard and insert to return list
                    vector<string> tmpChessBoard = emptyChessBoard;
                    for(int l=0;l<target;l++){
                        int thisRow = indexList[l][0];
                        int thisCol = indexList[l][1];
                        tmpChessBoard[thisRow][thisCol] = 'Q';
                    }
                    ret.push_back(tmpChessBoard);
                }else{
                    dfs(ret, indexList, chessCnt+1, target);
                }
                indexList.pop_back();
            }
        }
    }
};

int main(void){
    int n = 0;
    scanf("%d", &n);
    Solution *sol = new Solution();

    vector<vector<string> > ans;
    ans = sol->solveNQueens(n);
    for(int i=0;i<ans.size();i++){
        cout << i << ":" << endl;
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << endl;
        }
    }
    return 0;
}

