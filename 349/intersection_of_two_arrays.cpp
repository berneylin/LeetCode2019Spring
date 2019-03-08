#include<unordered_set>
using namespace std;


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> tmpSet;
        for(int i=0;i<nums1.size();i++) {
            if(tmpSet.find(nums1[i])==tmpSet.end()) tmpSet.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++) {
            if(tmpSet.find(nums2[i])==tmpSet.end()) tmpSet.insert(nums2[i]);
        }
        vector<int> ans;
        for(unordered_set<int>::iterator it=tmpSet.begin();it!=tmpSet.end();it++){
            if(find(nums1.begin(), nums1.end(), *it)!=nums1.end() && find(nums2.begin(), nums2.end(), *it)!=nums2.end()){
                ans.push_back(*it);
            }
        }
        return ans;
    }
};