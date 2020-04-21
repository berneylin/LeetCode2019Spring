#include<vector>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        int dp[m][n];
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0) dp[i][j] = 0;
                else {
                    dp[i][j] = 1;
                    if(i && j){
                        dp[i][j] += min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
                    }
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};