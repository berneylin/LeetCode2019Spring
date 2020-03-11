#include<vector>
using namespace std;

// solution1
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int numsLength = nums.size();
        int preIdx = 0;
        for (int i=0; i<numsLength; i++)
        {
            if(nums[i]%2==0) continue;
            int tmp = nums[i];
            nums[i] = nums[preIdx];
            nums[preIdx] = tmp;
            preIdx++;
        }
        return nums;
    }
};

// solution2
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int numsLength = nums.size();
        int left = 0, right = numsLength - 1;
        while(left<right){
            while(left < right && nums[left]%2!=0) left++;
            while(left < right && nums[right]%2==0) right--;
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
        }
        return nums;
    }
};