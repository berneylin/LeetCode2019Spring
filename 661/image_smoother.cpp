class Solution {
public:
    int coordinate[9][2] = {
        {0, 0},
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, -1},
        {0, 1},
        {1, -1},
        {1, 0},
        {1, 1}
    };

    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int row = M.size();
        if(row==0) return M;
        int col = M[0].size();
        if(col==0) return M;
        vector<vector<int> > ans(row, vector<int>(col, 0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                ans[i][j] = calcAverage(M, i, j);
            }
        }
        return ans;
    }

    int calcAverage(vector<vector<int>> &M, int i, int j) {
        int cnt = 0;
        int sum = 0;
        int row = M.size();
        int col = M[0].size();
        for(int k=0;k<9;k++){
            if(i+coordinate[k][0]<row && i+coordinate[k][0]>=0 && j+coordinate[k][1]<col && j+coordinate[k][1]>=0){
                cnt++;
                sum += M[i+coordinate[k][0]][j+coordinate[k][1]];
            }
        }
        return sum/cnt;
    }
};