class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int matrixRowSize = matrix.size();
        if(matrixRowSize==0) return ret;
        int matrixColSize = matrix[0].size();
        int lBound = 0, rBound = matrixColSize - 1, uBound = 0, dBound = matrixRowSize - 1;
        int i;
        while(lBound<=rBound && uBound <=dBound){
            if(lBound==rBound||uBound==dBound){
                if(lBound==rBound && lBound==uBound && lBound==dBound) ret.push_back(matrix[lBound][lBound]);
                else{
                    if(lBound!=rBound){  // uBound equals dBound
                        for(int i=lBound;i<=rBound;i++) ret.push_back(matrix[uBound][i]);
                    }else{  // lBound equals rBound
                        for(int i=uBound;i<=dBound;i++) ret.push_back(matrix[i][lBound]);
                    }
                }
                break;
            }

            i = lBound;
            while(i<rBound) ret.push_back(matrix[uBound][i++]);
            i = uBound;
            while(i<dBound) ret.push_back(matrix[i++][rBound]);
            i = rBound;
            while(i>lBound) ret.push_back(matrix[dBound][i--]);
            i = dBound;
            while(i>uBound) ret.push_back(matrix[i--][lBound]);
            lBound++;
            rBound--;
            dBound--;
            uBound++;
        }

        return ret;
    }
};