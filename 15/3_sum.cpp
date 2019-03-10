#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        set<vector<int> > S;
        if(nums.size()<2) return ans;
        sort(nums.begin(), nums.end());  // 对数组进行排序
        int numsSize = nums.size();
        for(int i=0;i<numsSize-2;i++){
            int l = i+1, r = numsSize-1;
            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];
                if(sum==0){
                    vector<int> tmpV = {nums[i], nums[l], nums[r]};
                    if(S.find(tmpV)==S.end()) {
                        ans.push_back(tmpV);
                        S.insert(tmpV);
                    }
                    l++;
                }else{
                    if(sum>0) r--;
                    else l++;
                }
            }
        }
        return ans;
    }
};