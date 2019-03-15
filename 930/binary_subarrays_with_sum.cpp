class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        const int ASize = A.size();
        if(S>ASize) return 0;
        int ansCnt = 0;
        int l = 0, r = 0;
        while(l<ASize){
            r = l;
            if(S==0&&A[l]==1){
                l++;
                continue;
            } // adhoc for zero condition
            int thisSum = A[r++];
            while(thisSum!=S){
                thisSum += A[r++];
                if(r==ASize && thisSum!=S) return ansCnt;
            }
            ansCnt++;
            while(r<ASize&&A[r]==0){
                r++;
                ansCnt++;
            }
            l++;
        }
        return ansCnt;
    }
};