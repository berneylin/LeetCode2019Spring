#include<vector>
using namespace std;


class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        if(A.empty() || A[0].empty()) return 0;
        int rowNum = A.size(), colNum = A[0].size();
        for(int i=0; i<rowNum; i++){
            for(int j=0; j<colNum; j++){
                if(i==0||i==rowNum-1||j==0||j==colNum-1){
                    if(A[i][j]) dfs(A, i, j);
                }
            }
        }
        int ans = 0;
        for(int i=0; i<rowNum; i++){
            for(int j=0; j<colNum; j++){
                if(A[i][j]) ans++;
            }
        }

        return ans;
    }
    
    void dfs(vector<vector<int> > &A, int i, int j){
        if(i<0||i>=A.size()||j<0||j>=A[0].size()||A[i][j]==0) return;
        A[i][j] = 0;
        dfs(A, i+1, j);
        dfs(A, i-1, j);
        dfs(A, i, j+1);
        dfs(A, i, j-1);
    }
};