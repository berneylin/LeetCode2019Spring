#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int moveArr[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int rowNum = grid.size(), colNum = grid[0].size();
        vector<vector<int> > color(rowNum, vector<int>(colNum, 0));
        int colorIdx = 0;
        vector<vector<bool> > visited(rowNum, vector<bool>(colNum, false));
        queue<pair<int, int> > tmpQ;
        for(int i=0; i<rowNum; i++){
            for(int j=0; j<colNum; j++){
                if(grid[i][j]==1){
                    tmpQ.push({i, j});
                    visited[i][j] = true;
                    int thisSize = 0;
                    while(!tmpQ.empty()){
                        int thisI = tmpQ.front().first, thisJ = tmpQ.front().second;
                        tmpQ.pop();
                        thisSize++;
                        for(int moveIdx=0; moveIdx<4; moveIdx++){
                            int nextI = thisI + moveArr[moveIdx][0];
                            int nextJ = thisJ + moveArr[moveIdx][1];
                            if(nextI<0||nextI>=rowNum||nextJ<0||nextJ>=colNum||visited[nextI][nextJ]||grid[nextI][nextJ]==0) continue;
                            tmpQ.push({nextI, nextJ});
                            visited[nextI][nextJ] = true;
                        }
                    }
                    colorIdx++;
                    dfs(grid, color, i, j, thisSize, colorIdx);
                }
            }
        }
        if(colorIdx==0) return 1; // 没有岛

        int maxSize = -1;
        for(int i=0; i<rowNum; i++){
            for(int j=0; j<colNum; j++){
                if(grid[i][j]==0){
                    int thisSize = 1;
                    unordered_set<int> colorUsed;
                    if(i && colorUsed.find(color[i-1][j])==colorUsed.end()) {
                        thisSize -= grid[i-1][j];
                        colorUsed.insert(color[i-1][j]);
                    }
                    if(j && colorUsed.find(color[i][j-1])==colorUsed.end()) {
                        thisSize -= grid[i][j-1];
                        colorUsed.insert(color[i][j-1]);
                    }
                    if(i+1<rowNum && colorUsed.find(color[i+1][j])==colorUsed.end()) {
                        thisSize -= grid[i+1][j];
                        colorUsed.insert(color[i+1][j]);
                    }
                    if(j+1<colNum && colorUsed.find(color[i][j+1])==colorUsed.end()) {
                        thisSize -= grid[i][j+1];
                        colorUsed.insert(color[i][j+1]);
                    }
                    if(thisSize>maxSize){
                        maxSize = thisSize;
                    }
                }
                else{
                    if(-grid[i][j]>maxSize){
                        maxSize = -grid[i][j];
                    }
                }
            }
        }
        return maxSize;
    }

    void dfs(vector<vector<int> > &grid, vector<vector<int> > &color, int i, int j, int newSize, int newColor){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==-newSize||grid[i][j]==0) return;
        grid[i][j] = -newSize;
        color[i][j] = newColor;
        dfs(grid, color, i+1, j, newSize, newColor);
        dfs(grid, color, i-1, j, newSize, newColor);
        dfs(grid, color, i, j+1, newSize, newColor);
        dfs(grid, color, i, j-1, newSize, newColor);
    }

};