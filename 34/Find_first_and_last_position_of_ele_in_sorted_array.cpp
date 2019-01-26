#include<vector>
using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        bool flag = false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                ret.push_back(i);
                for(int j=i+1;j<nums.size();j++){
                    if(nums[j]!=target){
                        ret.push_back(j-1);
                        break;
                    }
                    if(j==nums.size()-1) ret.push_back(j);
                }
                if(i==nums.size()-1) ret.push_back(i);
                flag = true;
                break;
            }
        }
        if(!flag){
            ret.push_back(-1);
            ret.push_back(-1);
        }
        return ret;
    }
};