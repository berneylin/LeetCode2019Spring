#include<vector>
using namespace std;

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        long long xdiff1 = points[0][0] - points[1][0], ydiff1 = points[0][1] - points[1][1];
        long long xdiff2 = points[0][0] - points[2][0], ydiff2 = points[0][1] - points[2][1];
        // 在一条直线上必须有： (ydiff2)/(xdiff2) == (ydiff1)/(xdiff1) ==> (ydiff2)*(xdiff1) == (ydiff1)*(xdiff2)
        long long product1 = ydiff2*xdiff1;
        long long product2 = ydiff1*xdiff2;
        return product1!=product2;
    }
};