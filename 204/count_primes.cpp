class Solution {
public:
    int countPrimes(int n) {
        if(n<=1) return 0;
        int primeCount = 0;
        bool primeMark[n+1];
        for(int i=2;i<=n;i++){
            primeMark[i] = true;
        }
        for(int i=2;i<=n;i++){
            if(primeMark[i]==false) continue;
            primeCount++;
            for(int k=2*i;k<=n;k+=i){
                primeMark[k] = false;
            }
        }
        return primeCount;
    }
};