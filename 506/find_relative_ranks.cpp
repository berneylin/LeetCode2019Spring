#include<vector>
#include<string>
#include<queue>

using namespace std;

struct cmp
{
    bool operator()(pair<int, int> pairA, pair<int, int> pairB){
        return pairA.second < pairB.second;
    }
};

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        // argsort with heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> maxHeap;
        for(int i=0; i<nums.size(); i++){
            maxHeap.push({i, nums[i]});
        }

        // init ansVec
        vector<string> ansVec(nums.size());

        int orderIdx = 1;
        // assign value
        while(!maxHeap.empty()){
            int currIdx = maxHeap.top().first;
            switch (orderIdx)
            {
            case 1:
                ansVec[currIdx] = "Gold Medal";
                break;
            case 2:
                ansVec[currIdx] = "Silver Medal";
                break;
            case 3:
                ansVec[currIdx] = "Bronze Medal";
                break;
            default:
                ansVec[currIdx] = to_string(orderIdx);
                break;
            }
            orderIdx++;
            maxHeap.pop();
        }

        return ansVec;
    }
};