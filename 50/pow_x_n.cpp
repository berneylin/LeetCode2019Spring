class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1.0;
        double weights = x;
        bool negFlag = false;
        if(x==1.0) return 1;
        if(n<0){
            negFlag = true;
        }
        long exponent = n;
        exponent = negFlag?-exponent:exponent;

        while(exponent){
            if(exponent&1) ret*=weights;
            exponent>>=1;
            weights*=weights;
        }
        return negFlag?1.0/ret:ret;
    }
};