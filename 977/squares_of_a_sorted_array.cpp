class Solution {
public:
    inline int abs(int x){
        return x>=0?x:-x;
    }
    inline int sqr(int x){
        return x*x;
    }
    vector<int> sortedSquares(vector<int>& A) {
        const int ASize = A.size();
        vector<int> ans(ASize);
        if(ASize==0) return ans;
        int zeroIdx = 0, insertIdx = 0;
        while(zeroIdx<ASize && A[zeroIdx]<0) zeroIdx++; //经过该循环后 zeroIdx指向0或第一个正数
        int i=zeroIdx-1, j=zeroIdx;
        while(insertIdx<ASize){
            if(i<0) ans[insertIdx] = sqr(A[j++]);
            else if(j>=ASize) ans[insertIdx] = sqr(A[i--]);
            else{
                if(abs(A[i])<abs(A[j])) ans[insertIdx] = sqr(A[i--]);
                else ans[insertIdx] = sqr(A[j++]);
            }
            insertIdx++;
        }
        return ans;
    }
};