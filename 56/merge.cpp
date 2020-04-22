#include<vector>
#include<algorithm>
using namespace std;

bool cmp(vector<int> v1, vector<int> v2){
    return v1[0]<v2[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return intervals;
        sort(intervals.begin(), intervals.end(), cmp);

        for(int i=0; i<intervals.size()-1; i++){
            vector<int> &i1 = intervals[i];
            vector<int> &i2 = intervals[i+1];

            if(i1[1]>=i2[0]){
                i1[1] = i1[1]>i2[1]?i1[1]:i2[1];
                intervals.erase(intervals.begin()+1);
                i--;
            }
        }

        return intervals;

    }
};