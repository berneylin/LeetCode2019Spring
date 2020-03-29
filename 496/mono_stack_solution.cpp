#include<stack>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> idxMap;
        stack<int> monoS;  // 单调递减栈

        for(int i=0; i<nums2.size(); i++){
            while(!monoS.empty() && monoS.top() < nums2[i]){
                idxMap.insert({monoS.top(), nums2[i]});
                monoS.pop();
            }
            monoS.push(nums2[i]);
        }
        while(!monoS.empty()){
            idxMap.insert({monoS.top(), -1});
            monoS.pop();
        }

        vector<int> ansVec(nums1.size());
        for(int i=0; i<nums1.size(); i++){
            ansVec[i] = idxMap[nums1[i]];
        }

        return ansVec;
    }
};