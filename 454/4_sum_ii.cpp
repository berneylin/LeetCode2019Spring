class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        const int N = A.size();
        if(!N) return 0;
        unordered_map<int, int> possibleTarget(2*N*N);
        int ansCnt = 0;
        for(int k=0;k<N;k++){
            for(int l=0;l<N;l++){
                possibleTarget[-(C[k]+D[l])]++;
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                auto it = possibleTarget.find(A[i]+B[j]);
                if(it!=possibleTarget.end()) ansCnt += it->second;
            }
        }
        return ansCnt;
    }
};