#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        int rowNum = matrix.size(), colNum = matrix[0].size();
        vector<vector<int> > dist(rowNum, vector<int>(colNum, 0x7FFFFFFF));
        vector<vector<bool> > visited(rowNum, vector<bool>(colNum, false));
        queue<pair<int, int> > tmpQueue;
        int moveArr[4][2] = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
        int thisDistance = 0;
        for(int i=0; i<rowNum; i++){
            for(int j=0; j<colNum; j++){
                if(matrix[i][j]==0){
                    tmpQueue.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        while(!tmpQueue.empty()){
            int qSize = tmpQueue.size();
            while (qSize--)
            {
                int thisI = tmpQueue.front().first;
                int thisJ = tmpQueue.front().second;
                tmpQueue.pop();
                dist[thisI][thisJ] = thisDistance;
                for(int i=0; i<4; i++){
                    int nextI = thisI + moveArr[i][0];
                    int nextJ = thisJ + moveArr[i][1];
                    if(nextI<0||nextI>=rowNum||nextJ<0||nextJ>=colNum||visited[nextI][nextJ]) continue;
                    tmpQueue.push({nextI, nextJ});
                    visited[nextI][nextJ] = true;
                }
            }
            thisDistance++;
        }
        return dist;
    }
};