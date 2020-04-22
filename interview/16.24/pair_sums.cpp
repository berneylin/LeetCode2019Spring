#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        vector<vector<int> > ansVec;
        unordered_map<int, int> targetMap;
        for(int i=0; i<nums.size(); i++){
            int thisDiff = target - nums[i];
            if(targetMap.find(thisDiff)!=targetMap.end()){
                // 存在数对
                vector<int> tmpVec = {thisDiff, nums[i]};
                ansVec.push_back(tmpVec);
                targetMap[thisDiff]--;
                if(targetMap[thisDiff]==0) targetMap.erase(thisDiff);
            }else{
                // 不存在数对 需要记录
                if(targetMap.find(nums[i])==targetMap.end()){
                    targetMap[nums[i]] = 0;
                }
                targetMap[nums[i]]++;
            }
        }
        return ansVec;
    }
};