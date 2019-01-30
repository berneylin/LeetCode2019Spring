class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int zeroRow=-1, zeroCol=-1;
        int cntRow = matrix.size(), cntCol = 0;
        if(cntRow) cntCol = matrix[0].size();
        for(int i=0;i<cntRow;i++){
            for(int j=0;j<cntCol;j++){
                if(matrix[i][j]==0){
                    zeroRow = i;
                    zeroCol = j;
                    break;
                }
            }
        }
        if(zeroRow==-1) return;

        for(int i=0;i<cntRow;i++){
            if(i==zeroRow) continue;
            for(int j=0;j<cntCol;j++){
                if(j==zeroCol) continue;
                if(matrix[i][j]==0){
                    matrix[i][zeroCol] = 0;
                    matrix[zeroRow][j] = 0;
                }
            }
        }

        for(int i=0;i<cntCol;i++){
            if(i==zeroCol) continue;
            if(matrix[zeroRow][i]==0){
                for(int j=0;j<cntRow;j++)
                    matrix[j][i] = 0;
            }
        }
        
        for(int i=0;i<cntRow;i++){
            if(i==zeroRow) continue;
            if(matrix[i][zeroCol]==0){
                for(int j=0;j<cntCol;j++){
                    matrix[i][j] = 0;
                } 
            }
        }

        for(int i=0;i<cntCol;i++) matrix[zeroRow][i] = 0;
        for(int i=0;i<cntRow;i++) matrix[i][zeroCol] = 0;

    }
};