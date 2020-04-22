#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        if(A.empty() || A[0].empty()) return 0;
        int rowNum = A.size(), colNum = A[0].size();
        queue<pair<int, int> > tmpQ;
        for(int i=0; i<rowNum; i++){
            if(A[i][0]) bfs(tmpQ, i, 0, A);
            if(A[i][colNum-1]) bfs(tmpQ, i, colNum-1, A);
        }
        for(int j=1; j<colNum-1; j++){
            if(A[0][j]) bfs(tmpQ, 0, j, A);
            if(A[rowNum-1][j]) bfs(tmpQ, rowNum-1, j, A);
        }
        int ans = 0;
        for(int i=0; i<rowNum; i++){
            for(int j=0; j<colNum; j++){
                if(A[i][j]) ans++;
            }
        }
        return ans;
    }

    void bfs(queue<pair<int, int> > &tmpQ, int i, int j, vector<vector<int> > &A){
        int rowNum = A.size(), colNum = A[0].size();
        tmpQ.push({i, 0});
        while(!tmpQ.empty()){
            A[tmpQ.front().first][tmpQ.front().second] = 0;
            tmpQ.pop();
            for(int moveIdx=0; moveIdx<4; moveIdx++){
                int nextI = tmpQ.front().first + moveArr[moveIdx][0];
                int nextJ = tmpQ.front().second + moveArr[moveIdx][1];
                if(nextI<0||nextI>=rowNum||nextJ<0||nextJ>=colNum||A[nextI][nextJ]==0) continue;
                tmpQ.push({nextI, nextJ});
            }
        }
    }
private:
    int moveArr[4][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
};