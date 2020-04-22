#include<algorithm>
#include<vector>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    if(a[0]==b[0]) return a[1] > b[1];
    else return a[0] < b[0];
}


class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty()) return 0;
        sort(envelopes.begin(), envelopes.end(), cmp);

        vector<int> tmpVec;
        for(int i=0; i<envelopes.size(); i++){
            int &thisWidth = envelopes[i][1];
            int lhs = 0, rhs = tmpVec.size();
            while(lhs<rhs){
                int mid = lhs + (rhs-lhs) / 2;
                if(tmpVec[mid]<thisWidth){
                    lhs = mid+1;
                }else{
                    rhs = mid;
                }
            }
            if(lhs==tmpVec.size()) tmpVec.push_back(thisWidth);
            else tmpVec[lhs] = thisWidth;
        }
        return tmpVec.size();
    }
};