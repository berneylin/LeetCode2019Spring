#include<cstdio>

// class Solution {
// public:
    bool judgeSquareSum(int c) {
        bool isSqrSum = false;
        long i=0;
        while(true){
            long iSqr = i*i;
            if(iSqr > (long)c) break;
            long half = (long)c - iSqr;
            bool isHalfSqr = false;
            if(half==0){
                isSqrSum = true;
                break;
            }else{
                long left = 1;
                long right = half;
                long mid;
                while(left<=right){
                    mid = left + (right-left)/2;
                    if(mid*mid==half){
                        isHalfSqr = true;
                        break;
                    }else{
                        if(mid*mid<half) left = mid+1;
                        else right = mid-1;
                    }
                }
            }
            if(isHalfSqr){
                isSqrSum = true;
                break;
            }
            i++;
        }
        return isSqrSum;
    }
// };

int main(void){
    int x;
    scanf("%d",&x);
    printf("%d", judgeSquareSum(x));
}