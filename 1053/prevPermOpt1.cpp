#include<stack>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        if(A.size()<=1) return A;
        int lhs = -1, rhs = -1;
        stack<int> monoStack;
        for(int i=0; i<A.size(); i++){
            while(!monoStack.empty() && A[monoStack.top()]<A[i]){
                monoStack.pop();
            }
            if(!monoStack.empty() && (A[monoStack.top()]>A[i] && lhs<=monoStack.top())){
                lhs = monoStack.top();
                rhs = i;
            }
            
            monoStack.push(i);
        }

        if(lhs!=-1){
            swap(A[lhs], A[rhs]);
        }

        return A;
    }
};