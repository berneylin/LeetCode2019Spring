#include<queue>
#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int> > ansVec;
        int rowNum = matrix.size();
        if(rowNum==0) return ansVec;
        int colNum = matrix[0].size();
        if(colNum==0) return ansVec;
        queue<pair<int, int> > bfsQ;

        int moveArray[4][2] = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        int pacificVisit[rowNum][colNum];
        int atlanticVisit[rowNum][colNum];
        memset(pacificVisit, 0, sizeof(int)*rowNum*colNum);
        memset(atlanticVisit, 0, sizeof(int)*rowNum*colNum);

        // pacific 左边界和上边界一定可达
        for(int i=0; i<rowNum; i++) {
            bfsQ.push({i, 0});
        }
        for(int j=0; j<colNum; j++) {
            bfsQ.push({0, j});
        }

        while(!bfsQ.empty()){
            int curI = bfsQ.front().first;
            int curJ = bfsQ.front().second;
            bfsQ.pop();
            
            pacificVisit[curI][curJ] = 1;
            for(int moveIdx=0; moveIdx<4; moveIdx++){
                int nextI = curI+moveArray[moveIdx][0];
                int nextJ = curJ+moveArray[moveIdx][1];
                if(nextI<0||nextI>=rowNum||nextJ<0||nextJ>=colNum||pacificVisit[nextI][nextJ]==1||matrix[nextI][nextJ]<matrix[curI][curJ]){
                    continue;
                }
                bfsQ.push({nextI, nextJ});
            }
        }

        // atlantic 右边界和下边界一定可达
        for(int i=0; i<rowNum; i++) {
            bfsQ.push({i, colNum-1});
        }

        for(int j=0; j<colNum; j++) {
            bfsQ.push({rowNum-1, j});
        }

        while(!bfsQ.empty()){
            int curI = bfsQ.front().first;
            int curJ = bfsQ.front().second;
            bfsQ.pop();
            
            atlanticVisit[curI][curJ] = 1;
            for(int moveIdx=0; moveIdx<4; moveIdx++){
                int nextI = curI+moveArray[moveIdx][0];
                int nextJ = curJ+moveArray[moveIdx][1];
                if(nextI<0||nextI>=rowNum||nextJ<0||nextJ>=colNum||atlanticVisit[nextI][nextJ]==1||matrix[nextI][nextJ]<matrix[curI][curJ]){
                    continue;
                }
                bfsQ.push({nextI, nextJ});
            }
        }
        
        for(int i=0; i<rowNum; i++){
            for(int j=0; j<colNum; j++){
                if(atlanticVisit[i][j] && pacificVisit[i][j]) {
                    vector<int> thisAns;
                    thisAns.push_back(i);
                    thisAns.push_back(j);
                    ansVec.push_back(thisAns);
                }
            }
        }

        return ansVec;
    }
};