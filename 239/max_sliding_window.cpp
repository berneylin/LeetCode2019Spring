#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int numsSize = nums.size();
        vector<int> rtnAns;
        if(numsSize==0){
            return rtnAns;
        }
        deque<int> windowIdxQueue;
        for(int i=0; i<numsSize; i++){
            if(!windowIdxQueue.empty() && windowIdxQueue.front() == i-k) windowIdxQueue.pop_front();
            while(!windowIdxQueue.empty() && nums[windowIdxQueue.back()] < nums[i]) windowIdxQueue.pop_back();
            windowIdxQueue.push_back(i);
            if(i>=k-1) rtnAns.push_back(nums[windowIdxQueue.front()]);
        }

        return rtnAns;
    }
};