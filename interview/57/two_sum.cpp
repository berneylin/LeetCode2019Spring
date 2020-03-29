#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> rtnVec;
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            if (nums[l] + nums[r] == target)
            {
                rtnVec.push_back(nums[r]);
                rtnVec.push_back(nums[l]);
                break;
            }
            else if (nums[l] + nums[r] < target)
            {
                l++;
            }
            else if (nums[l] + nums[r] > target)
            {
                r--;
            }
        }
        return rtnVec;
    }
};