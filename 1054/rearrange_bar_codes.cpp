#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b){
    return a.second>b.second;
}


class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if(barcodes.size()<=2) return barcodes;
        unordered_map<int, int> numCnt;
        for(const int &x: barcodes){
            if(numCnt.find(x)==numCnt.end()){
                numCnt[x] = 0;
            }
            numCnt[x]++;
        }

        vector<pair<int, int> > sortedCnt;
        for(const auto &cntPair: numCnt){
            sortedCnt.push_back({cntPair.first, cntPair.second});
        }
        sort(sortedCnt.begin(), sortedCnt.end(), cmp);

        int idx = 0, curNumIdx = 0, N = barcodes.size();
        vector<int> rtnVec(barcodes.size());

        while(N--){
            rtnVec[idx] = sortedCnt[curNumIdx].first;
            sortedCnt[curNumIdx].second--;
            if(sortedCnt[curNumIdx].second==0){
                curNumIdx++;
            }
            idx += 2;
            if(idx>=barcodes.size()) idx=1;
        }
        
        return rtnVec;
        
    }
};