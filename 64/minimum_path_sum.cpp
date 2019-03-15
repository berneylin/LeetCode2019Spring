class Solution {
public:
    inline int min(int a, int b){
        return a<b?a:b;
    }
    int minPathSum(vector<vector<int>>& grid) {
        const int M = grid.size();
        if(M==0) return 0;
        const int N = grid[0].size();
        if(N==0) return 0;
        vector<vector<int> > dp(M, vector<int>(N, 0));
        dp[0][0] = grid[0][0];
        for(int i=1;i<M;i++) dp[i][0] = (dp[i-1][0]+grid[i][0]);
        for(int j=1;j<N;j++) dp[0][j] = (dp[0][j-1]+grid[0][j]);
        for(int i=1;i<M;i++){
            for(int j=1;j<N;j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1])+grid[i][j];
            }
        }
        return dp[M-1][N-1];
    }
};