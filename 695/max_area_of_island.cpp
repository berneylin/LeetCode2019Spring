#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rowNum = grid.size();
        if(rowNum==0) return 0;
        int colNum = grid[0].size();
        if(colNum==0) return 0;

        int maxSize = -1;
        queue<pair<int, int> > bfsQ;
        vector<vector<bool> > visited(rowNum, vector<bool>(colNum, false));

        for(int i=0;i<rowNum;i++){
            for(int j=0;j<colNum;j++){
                if(grid[i][j] == 0 || visited[i][j]) continue;
                // gird[i][j] 为之前没有达到过的1
                int thisSize = 0;
                bfsQ.push({i, j});
                while(!bfsQ.empty()){
                    int curI = bfsQ.front().first;
                    int curJ = bfsQ.front().second;
                    bfsQ.pop();

                    if(curI<0||curI>=rowNum||curJ<0||curJ>=colNum||grid[curI][curJ]!=1|| visited[curI][curJ])
                        continue;

                    thisSize++;
                    visited[curI][curJ] = true;

                    bfsQ.push({curI+1, curJ});
                    bfsQ.push({curI-1, curJ});
                    bfsQ.push({curI, curJ+1});
                    bfsQ.push({curI, curJ-1});

                }
                if (thisSize>maxSize) {
                    maxSize = thisSize;
                }
            }
        }

        return maxSize;

    }
};