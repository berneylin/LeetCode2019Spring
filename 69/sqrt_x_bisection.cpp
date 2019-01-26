// #include<stdio.h>
class Solution {
public:
    int mySqrt(int x) {
        int ret;
        if(x==0) return 0;
        else if(x==1) return 1;
        else{
            int left = 0;
            int right = x;
            int mid;
            while(left<=right){ // find the first number which square larger than target number `x'
                mid = left + (right - left) / 2;
                if(mid==x/mid) return mid;
                else{
                    if(mid<x/mid) left = mid+1;
                    else right = mid-1;
                }
            }
            ret = right;
        }
        return ret;
    }
};


// int main(void){
//     int x;
//     scanf("%d",&x);
//     printf("%d",mySqrt(x));
//     return 0;
// }