class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> res;
        int row = A.size();
        if(row==0) return res;
        int col = A[0].size();
        if(col==0) return res;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0){
                    vector<int> tmp;
                    tmp.push_back(A[i][j]);
                    res.push_back(tmp);
                }else{
                    res[j].push_back(A[i][j]);
                }
            }
        }
        return res;
    }
};