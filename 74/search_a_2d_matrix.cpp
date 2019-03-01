class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        if(matrix.size()==0) return false;
        if(matrix[0].size()==0) return false;

        int rowsCnt = matrix.size();
        int col = matrix[0].size() - 1;
        while(row<rowsCnt&&col>=0){
            while(row<rowsCnt&&col>=0){
                if(matrix[row][col]==target) return true;
                else if(matrix[row][col]<target) row++;
                else if(matrix[row][col]>target) col--;
            }
        }
        return false;
    }
};