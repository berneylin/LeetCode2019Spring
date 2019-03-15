class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if(A.empty() || A.size()==1) return true;
        bool ansFlag = true;
        bool monoMode = true;  // true代表递增，false代表递减
        int ASize = A.size();
        int i=0, j=1;

        while(A[i]==A[j]&&j<ASize-1){
            i++;
            j++;
        }
        monoMode = A[i]<A[j];
        while(ansFlag && j<ASize-1){
            ansFlag = monoMode?(A[i]<=A[j]&&A[j]<=A[j+1]):(A[i]>=A[j]&&A[j]>=A[j+1]);
            i++;
            j++;
        }
        return ansFlag;
    }
};