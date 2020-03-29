#include<stack>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if(nums.empty()) return nums;
        map<int, int> idxMap;
        stack<int> monoS;
        int i = 0;
        for(int i=0; i<nums.size(); i++){
            while(!monoS.empty() && nums[monoS.top()] < nums[i]){
                idxMap.insert({monoS.top(), nums[i]});
                monoS.pop();
            }
            monoS.push(i);
        }

        // monoS中存放的索引出栈是单调减的
        // stack中剩下的数出栈是单调增的
        int maxI = monoS.top();
        for(int i=0; i<maxI; i++){
            while(!monoS.empty() && nums[monoS.top()] < nums[i]){
                idxMap.insert({monoS.top(), nums[i]});
                monoS.pop();
            }
            monoS.push(i);
        }

        while(!monoS.empty()){
            if(idxMap.find(monoS.top())==idxMap.end()){
                idxMap.insert({monoS.top(), -1});
            }
            monoS.pop();
        }

        vector<int> ansVec(nums.size());
        for(int i=0; i<nums.size(); i++){
            ansVec[i] = idxMap[i];
        }

        return ansVec;
    }
};