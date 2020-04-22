#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first==b.first) return a.second>b.second;
    else return a.first<b.first;
}


class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        if(height.size()<=1) return height.size();

        vector<pair<int, int> > pairVec;
        for(int i=0; i<height.size(); i++){
            pairVec.push_back({height[i], weight[i]});
        }

        sort(pairVec.begin(), pairVec.end(), cmp);

        int dp[height.size()];
        int maxLen = 0;

        for(int i=0; i<height.size(); i++){
            int lhs = 0, rhs = maxLen;
            int &thisWeight = pairVec[i].second;
            while(lhs < rhs){
                int mid = lhs + (rhs - lhs) / 2;
                if(dp[mid]<thisWeight){
                    lhs = mid + 1;
                }else{
                    rhs = mid;
                }
            }
            dp[lhs] =thisWeight;
            if(lhs == maxLen) maxLen++;
        }

        return maxLen;
    }
};