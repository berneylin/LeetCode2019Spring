#include<set>
#include<vector>
#include<cmath>
using namespace std;


class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        set<pair<int, int> > pointsSet;
        int minSize = 0x7FFFFFFF;
        for(const auto &eachPoint: points){
            pointsSet.insert({eachPoint[0], eachPoint[1]});
        }
        for(int i=0; i<points.size(); i++){
            int x1 = points[i][0], y1 = points[i][1];
            for(int j=i+1; j<points.size(); j++){
                int x2 = points[j][0], y2 = points[j][1];
                if(x1 == x2 || y1 == y2) continue;
                int thisSize = abs((x1-x2)*(y1-y2));
                if(thisSize>=minSize) continue;
                if((pointsSet.find({x1, y2})!=pointsSet.end()) && (pointsSet.find({x2, y1})!=pointsSet.end())) minSize = thisSize;
            }
        }
        return minSize==0x7FFFFFFF?0:minSize;
    }
};