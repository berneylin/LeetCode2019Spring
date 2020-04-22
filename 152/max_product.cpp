#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ans = nums[0];
        int thismin = nums[0], thismax = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i]<0){
                // 负数乘上会使最大的变最小，最小的变最大, 提前交换
                int tmp = thismax;
                thismax = thismin;
                thismin = tmp;
            }
            thismax = max(nums[i], nums[i]*thismax);
            thismin = min(nums[i], nums[i]*thismin);

            ans = max(ans, thismax);
        }

        return ans;
    }
};