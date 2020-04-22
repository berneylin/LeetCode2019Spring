#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int lhs = 0, rhs = height.size() - 1, ans = 0;
        while(lhs<=rhs){
            ans = max(ans, (rhs-lhs)*min(height[lhs], height[rhs]));
            if(height[lhs]<height[rhs]){
                lhs++;
            }else rhs--;
        }

        return ans;
    }
};


