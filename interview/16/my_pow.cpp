class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        bool negFlag = n < 0;
        long absN = n;
        if (negFlag) absN *= -1;

        while(absN){
            if(absN&1) ans *= x;
            x *= x;
            absN >>= 1;            
        }
        return negFlag?1/ans:ans;
    }
};