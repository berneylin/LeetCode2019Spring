#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int tmp = grid[r0][c0];
        int m = grid.size(),n = grid[0].size();
        vector<vector<bool>> flag(m,vector<bool>(n));
        dfs(grid,r0,c0,color,tmp,flag);
        return grid;
    }
    void dfs(vector<vector<int>>& grid,int r,int c,const int &color,const int &tmp,vector<vector<bool>>& flag)
    {
        if(r>=grid.size() || r<0 || c>=grid[0].size() || c<0 || grid[r][c]!=tmp || flag[r][c])
            return;
        flag[r][c] = true;
        if(r==0 || r==grid.size()-1 || c==0 || c==grid[0].size()-1)
            grid[r][c] = color;
        if(r<grid.size()-1 && !flag[r+1][c] && grid[r+1][c]!=tmp || r>0 && !flag[r-1][c] && grid[r-1][c]!=tmp || c<grid[0].size()-1 && !flag[r][c+1] && grid[r][c+1]!=tmp || c>0 && !flag[r][c-1] && grid[r][c-1]!=tmp)
            grid[r][c] = color;

        dfs(grid,r-1,c,color,tmp,flag);
        dfs(grid,r,c-1,color,tmp,flag);
        dfs(grid,r+1,c,color,tmp,flag);
        dfs(grid,r,c+1,color,tmp,flag);
    }
};