#include<set>

using namespace std;



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> numsSet;
        for(const auto& num: nums) numsSet.insert(num);

        int longestLength = 0;
        for(const auto& num: nums){
            if(numsSet.find(num-1)==numsSet.end()){
                int thisNum = num, thisLength = 1;
                while(numsSet.find(thisNum+1)!=numsSet.end()){
                    thisLength++;
                    thisNum++;
                }
                if(thisLength>longestLength) longestLength = thisLength;
            }
        }

        return longestLength;
    }
};