class Solution {
public:
    long gcd(long m, long n) {
        long r;
        if(m<n){
            r = n;
            n = m;
            m = r;
        }
        while(1) {
            r = m % n;
            if(r == 0)
                break;
            m = n;
            n = r;
        }
        return n;	
    }

    int uniquePaths(int l1, int l2) {
        if(l1==l2&&l1==1) return 1;
        long n = l1+l2-2;
        long k = l1==1?l2-1:l1-1;
        /* calc C(n, k) */
        vector<long> tmp;
        for(long i=0;i<k;i++){
            tmp.push_back(n-k+1+i);
        }
        for(long i=1;i<=k;i++){
            tmp.push_back(i);
        }
        for(int i=0;i<k;i++){
            // i for index
            for(int j=0;j<k;j++){
                long thisGCD = gcd(tmp[i], tmp[j+k]);
                if(thisGCD!=1){
                    tmp[i] /= thisGCD;
                    tmp[j+k]/= thisGCD;
                }
            }
        }
        long ret = 1;
        for(int i=0;i<tmp.size();i++){
            if(i==1) continue;
            if(i<k) ret*= tmp[i];
            else ret/=tmp[i];
        }
        
        return (int)ret;
    }
};