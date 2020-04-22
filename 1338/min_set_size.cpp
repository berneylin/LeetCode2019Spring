#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool cmp(int &a, int &b){
    return a>b;
}

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int>  cntMap;
        for(const int &num: arr){
            if(cntMap.find(num)==cntMap.end()) cntMap[num] = 0;
            cntMap[num]++;
        }
        vector<int> tmpVec;
        for(const auto &eachPair: cntMap){
            tmpVec.push_back(eachPair.second);
        }
        sort(tmpVec.begin(), tmpVec.end(), cmp);
        int ans = 0, removeCnt = 0;
        while(removeCnt<(arr.size()>>1)){
            removeCnt += tmpVec[ans];
            ans++;
        }
        return ans;
    }
};