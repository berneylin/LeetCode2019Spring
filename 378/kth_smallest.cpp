#include<vector>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int min = matrix[0][0], max = matrix[matrix.size()-1][matrix[0].size()-1];
        while(min<max){
            int mid = min + ((max-min)>>1);
            int cnt = 0;
            for(int i=0; i<matrix.size(); i++){
                for(int j=0; j<matrix.size(); j++){
                    if(matrix[i][j]<=mid){
                        cnt ++;
                    }else break;
                }
            }
            if(cnt<k){
                min = mid+1;
            }else{
                max = mid;
            }
        }
        return min;
    }
};