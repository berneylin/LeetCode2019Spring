#include<algorithm>
#include<vector>
using namespace std;


class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        if(points.size()<=2) return points.size();

        for(int i=0; i<points.size(); i++){
            int same = 1;
            int &ax = points[i][0], &ay = points[i][1];
            for(int j=i+1; j<points.size(); j++){
                int &bx = points[j][0], &by = points[j][1];
                int count = 0;
                if(ax==bx && ay==by) {
                    same++;
                }else{
                    count++;
                    long abx = (long)ax - (long)bx;
                    long aby = (long)ay - (long)by;
                    for(int k=j+1; k<points.size(); k++){
                        int &cx = points[k][0], &cy = points[k][1];
                        long acx = (long)ax - (long)cx;
                        long acy = (long)ay - (long)cy;
                        if(acy*abx == aby*acx) count++;
                    }
                }
                ans = max(ans, count+same);
            }
            if(ans>points.size()/2) return ans;
        }

        return ans;
    }
};