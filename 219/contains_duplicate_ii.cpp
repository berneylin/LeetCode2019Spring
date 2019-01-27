#include<cmath>
#include<unordered_map>
using namespace std;


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        bool ret = false;
        unordered_map<int, int> M;
        int numsLength = nums.size();

        for(int i=0;i<numsLength;i++){
            if(M.find(nums[i])==M.end()) M.insert(pair<int, int>(nums[i], i)); //if current number not appear before
            else{  // current number is repeated
                ret = (abs(M[nums[i]] - i)>k)?false:true;
                if(ret) break;
                else{// for case [1,0,1,1] and k=1
                    // update the index
                    M[nums[i]] = i;
                }
            }
        }
        return ret;
    }
};