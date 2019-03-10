class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        if(A.empty()) return 0;
        int maxNum = A[0], minNum = A[0], ASize = A.size();
        for(int i=0;i<ASize;i++) {
            maxNum = maxNum>A[i]?maxNum:A[i];
            minNum = minNum<A[i]?minNum:A[i];
        }
        return (maxNum-minNum)<=2*K?0:(maxNum-minNum-2*K);
    }
};