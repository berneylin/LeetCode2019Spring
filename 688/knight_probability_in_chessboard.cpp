class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        double dp[N][N];
        double ans = 0.0;
        memset(dp, 0, sizeof(double)*N*N);
        int coordinateChange[8][2] = {
            {-1, -2},
            {-2, -1},
            {-2, 1},
            {-1, 2},
            {1, 2},
            {2, 1},
            {2, -1},
            {1, -2}
        };
        dp[r][c] = 1.0;  // 初始化
        while(K--){
            double tmp[N][N];
            memset(tmp, 0, sizeof(double)*N*N);
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if(dp[i][j]!=0){
                        for(int k=0;k<8;k++){
                            int nextI = i + coordinateChange[k][0];
                            int nextJ = j + coordinateChange[k][1];
                            if(nextI>=0 && nextI<N && nextJ>=0 && nextJ<N) tmp[nextI][nextJ] += 0.125*dp[i][j];
                        }
                    }
                }
            }
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    dp[i][j] = tmp[i][j];
                }
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                ans += dp[i][j];
            }
        }
        return ans;
    }
};