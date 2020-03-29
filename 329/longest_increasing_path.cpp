#include<vector>
using namespace std;


class Solution {
public:
    int moveArr[4][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rowNums = matrix.size();
        if(rowNums==0) return 0;
        int colNums = matrix[0].size();
        if(colNums==0) return 0;

        vector<vector<int> > visited(rowNums, vector<int>(colNums, 0));
           
        int maxLen = 1;
        for(int i=0; i<rowNums; i++){
            for(int j=0; j<colNums; j++){
                if(visited[i][j]==0){
                    int thisLen = dfs(matrix, i, j, visited);
                    if(thisLen>maxLen) maxLen = thisLen;
                }
            }
        }

        return maxLen;
        
    }

    int dfs(vector<vector<int> > &matrix, int i, int j, vector<vector<int> > &visited){
        if(visited[i][j]!=0) return visited[i][j];

        int thisMaxLen = 0;
        for(int moveIdx=0; moveIdx<4; moveIdx++){
            int nextI = moveArr[moveIdx][0] + i;
            int nextJ = moveArr[moveIdx][1] + j;

            if(nextI<0||nextI>=matrix.size()||nextJ<0||nextJ>=matrix[0].size()||matrix[nextI][nextJ]<=matrix[i][j])
                continue;
            int thisLen = dfs(matrix, nextI, nextJ, visited);
            if(thisLen>thisMaxLen) thisMaxLen = thisLen;
            visited[i][j] = thisMaxLen+1>visited[i][j]?thisMaxLen+1:visited[i][j];
        }
        return thisMaxLen+1;
    }
};