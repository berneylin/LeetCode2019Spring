class Solution {
public:
    int mySqrt(int x) {
        int ret = 0;
        if (x==0) return 0;
        else if (x==1) return 1;
        else{
            long xLong = x;
            for(long i=1;i<xLong;i++){
                if(i*i>xLong){
                    ret = i-1;
                    break;
                }
            }
        }
        return ret;
    }
};