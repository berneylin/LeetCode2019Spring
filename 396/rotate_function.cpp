class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int ASize = A.size();
        long sum = 0, F = 0;
        for(int i=0;i<ASize;i++){
            sum += A[i];
            F += i * A[i];
        }
        long maxF = F;
        for(int i=ASize-1;i>=0;i--){
            F += sum;
            for(int j=0;j<ASize;j++) F -= A[i];  // 防止ASize * A[i] 溢出
            maxF = maxF>F?maxF:F;
        }
        return (int)maxF;
    }
};