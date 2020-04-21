#include<vector>
#include<algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()<=1) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int ans = 0;
        int baseIdx=0, idx=0;
        while(idx<intervals.size()){
            if(intervals[idx][0]>=intervals[baseIdx][1]){
                // not overlap
                baseIdx = idx;
                ans++;
            }
            idx++;
        }
        ans++;
        return intervals.size() - ans;
    }
};