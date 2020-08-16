#include<vector>
using namespace std;


class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int n = A.size();
        if(L<=0 || M<=0 || L+M>n) return 0;
        int sum[n+1];
        sum[0] = 0;
        int curSum = 0;
        for(int i=1; i<=n; i++){
            curSum += A[i-1];
            sum[i] = curSum;
        }
        int ans = 0;
        for(int i=0; i<=n-M-L+1; i++){
            int curLSum = sum[i+L] - sum[i];
            for(int j=i+L; j<=n-M; j++){
                int curMSum = sum[j+M] - sum[j];
                if(curLSum+curMSum > ans) 
                    ans = curLSum + curMSum;
            }
        }

        for(int i=0; i<=n-M-L+1; i++){
            int curMSum = sum[i+M] - sum[i];
            for(int j=i+M; j<=n-L; j++){
                int curLSum = sum[j+L] - sum[j];
                if(curLSum+curMSum > ans) 
                    ans = curLSum + curMSum;
            }
        }

        return ans;

    }
};