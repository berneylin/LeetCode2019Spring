#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = 0, sumB = 0;
        for(const int &num: A) sumA += num;
        for(const int &num: B) sumB += num;
        int diff = sumA - sumB;
        diff /= 2;
        vector<int> ansVec;
        for(int i=0; i<A.size(); i++) 
            A[i] -= diff;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int aIdx = 0, bIdx = 0;
        while(aIdx < A.size() && bIdx < B.size()){
            if(A[aIdx]<B[bIdx]) aIdx++;
            else if(A[aIdx]>B[bIdx]) bIdx++;
            else{
                ansVec.push_back(A[aIdx]+diff);
                ansVec.push_back(B[bIdx]);
                break;
            }
        }
        return ansVec;
    }
};