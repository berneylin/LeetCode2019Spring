#include<vector>

using namespace std;


class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->mMatrix = matrix;
        if(!this->mMatrix.empty() && !this->mMatrix[0].empty()){
            vector<vector<int> > sumArray(matrix.size(), vector<int>(matrix[0].size(), 0));
            for(int i=1; i<=matrix.size(); i++){
                for(int j=1; j<=matrix[0].size(); j++){
                    sumArray[i][j] = sumArray[i-1][j] + sumArray[i][j-1] - sumArray[i-1][j-1] + matrix[i-1][j-1];
                }
            }
            dp = sumArray;            
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(this->mMatrix.empty() || this->mMatrix[0].empty()) return 0;
        return dp[row2+1][col2+1] - dp[row1][col2+1] - dp[row2+1][col1] + dp[row1][col1];
    }
private:
    vector<vector<int> > mMatrix;
    vector<vector<int> > dp;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */