#include<algorithm>
using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(Interval x, Interval y){
        return x.start<y.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        int thisStart, thisEnd;
        if(intervals.empty()||intervals.size()==1) return intervals;
        // lambda version
        // sort(intervals.begin(), intervals.end(), [](Interval x, Interval y){return x.start<y.start;});
        sort(intervals.begin(), intervals.end(), cmp);
        int thisIdx = 0;  // index that the node need modify
        thisStart = intervals[0].start;
        thisEnd = intervals[0].end;
        int originalSize = intervals.size();
        for(int i=1;i<originalSize;i++){
            if(intervals[i].start>thisEnd){
                // update thisIdx Node
                intervals[thisIdx].start = thisStart;
                intervals[thisIdx].end = thisEnd;
                thisIdx ++;
                thisStart = intervals[i].start;
                thisEnd = intervals[i].end;
            }
            else{  // update thisEnd
                thisEnd = max(thisEnd, intervals[i].end);
            }
            if(i==originalSize-1){
                // traverse to the tail node, always update
                intervals[thisIdx].start = thisStart;
                intervals[thisIdx].end = thisEnd;
                thisIdx++;
            }
        }
        for(int i=0;i<originalSize-thisIdx;i++) intervals.pop_back();
        return intervals;
    }
};