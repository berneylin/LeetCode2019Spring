#include<algorithm>
using namespace std;

const static auto io_speed_up = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}();


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool ret = false;
        sort(nums.begin(), nums.end());
        int numsLength = nums.size();

        for(int i=0;i<numsLength-1;i++){
            if(nums[i]==nums[i+1]){
                ret = true;
                break;
            }
        }

        return ret;
    }
};