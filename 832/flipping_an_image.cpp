class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if(A.empty() || A[0].empty()) return A;
        int tmp;
        const int ROW = A.size(), COL = A[0].size(), HALFCOL = COL/2;
        for(int i=0;i<ROW;i++){
            for(int j=0;j<HALFCOL;j++){
                A[i][j] = (A[i][j])?0:1;
                A[i][COL-j-1] = (A[i][COL-j-1])?0:1;
                tmp = A[i][j];
                A[i][j] = A[i][COL-j-1];
                A[i][COL-j-1] = tmp;
            }
        }
        if(COL&1){
            for(int i=0;i<ROW;i++){
                A[i][HALFCOL] = (A[i][HALFCOL])?0:1;
            }
        }
        return A;
    }
};