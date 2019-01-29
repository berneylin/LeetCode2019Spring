#include<cmath>

class Solution {
public:
    int totalNQueens(int n) {
        int ret = 0;
        vector<int*> indexList;
        dfs(ret, indexList, 0, n);
        return ret;
    }

    void dfs(int &solCnt, vector<int*> &indexList, int chessCnt, int target){
        int i = chessCnt;
        for(int j=0;j<target;j++){
            bool legalFlag = true;
            for(int k=0;k<chessCnt;k++){
                if(indexList[k][0]==i||indexList[k][1]==j||abs(i - indexList[k][0])==abs(j - indexList[k][1])){
                    legalFlag = false;
                    break;
                }
            }
            if(legalFlag){
                if(chessCnt+1==target) solCnt++;
                else{
                    int tmp[2];
                    tmp[0] = i;
                    tmp[1] = j;
                    indexList.push_back(tmp);
                    dfs(solCnt, indexList, chessCnt+1, target);
                    indexList.pop_back();
                }
            }
        }
    }
};