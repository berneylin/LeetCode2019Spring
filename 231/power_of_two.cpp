class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1) return true;
        else if(n==0) return false;
        bool ret = false;
        
        while((n&1)!=1){
            n>>=1;
        }
        if(n==1) 
            ret = true;
        return ret; 
    }
};