#include<vector>
using namespace std;

class Solution {
public:
    inline int min(int a, int b){
        return a<b?a:b;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int numRow = triangle.size();
        if (numRow==0) return 0;
        for(int i=numRow-2; i>=0; i--){
            for(int j=0; j<=i; j++){
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};