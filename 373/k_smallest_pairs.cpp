#include<vector>
#include<queue>
using namespace std;
struct tmpStruct //重写仿函数
{
    bool operator() (pair<int, int> &pair1, pair<int, int> &pair2) 
    {
        return pair1.first+pair1.second<pair2.first+pair2.second;
    }
};


class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, tmpStruct> priorQ;
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                if(priorQ.size() < k){
                    priorQ.push({nums1[i], nums2[i]});
                }else{
                    if(priorQ.top().first+priorQ.top().second > nums1[i]+nums2[j]){
                        priorQ.pop();
                        priorQ.push({nums1[i], nums2[j]});
                    }
                }
                
            }
        }
        vector<vector<int>> ansVec;
        while(!priorQ.empty()){
            ansVec.push_back({priorQ.top().first, priorQ.top().second});
            priorQ.pop();
        }
        return ansVec;
    }
};