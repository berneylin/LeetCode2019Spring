#include<vector>
using namespace std;



class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> ret;
        int numsOfSubsets = 1<<nums.size();  // calc 2^(nums.size())
        for(int i=0;i<numsOfSubsets;i++){  // overall 2^(nums.size()) subsets
            int thisBinIdx = i;
            int thisArrIdx = 0;
            vector<int> subsetElem;
            while(thisBinIdx){
                if(thisBinIdx&1){
                    subsetElem.push_back(nums[thisArrIdx]);
                }
                thisBinIdx>>=1;
                thisArrIdx++;
            }
            ret.push_back(subsetElem);
        }
        return ret;
    }
};