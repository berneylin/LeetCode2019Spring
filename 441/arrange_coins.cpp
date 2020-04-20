class Solution {
public:
    int arrangeCoins(int n) {
        if(n<=0) return n;
        int l = 0, r = n;
        while(l<=r){
            long m = l + ((r-l)>>1);
            long thisSum = m*(m+1)/2;
            if(thisSum==n){
                return m;
            }
            else if(thisSum<n){
                l = m+1;
            }else if(thisSum>n){
                r = m-1;
            }
        }
        return r;
    }
};