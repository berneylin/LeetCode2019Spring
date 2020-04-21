#include<vector>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        sort(points.begin(), points.end(), cmp);
        int ans = 0;
        int baseIdx = 0, idx = 0;
        while(idx<points.size()){
            if(points[baseIdx][1]<points[idx][0]){
                ans++;
                baseIdx = idx;
            }
            idx++;
        }
        return ans+1;
    }
};