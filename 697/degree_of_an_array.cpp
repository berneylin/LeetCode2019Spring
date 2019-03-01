#include<unordered_map>
using namespace std;


class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> sM;
        unordered_map<int, int> eM;
        unordered_map<int, int> cntM;
        int numsSize = nums.size();
        int maxCnt = 0;
        int thisNum;
        int ans=nums.size();
        for(int i=0;i<numsSize;i++){
            thisNum = nums[i];
            if(sM.find(thisNum)==sM.end()){
                sM.insert(make_pair(thisNum, i));
                eM.insert(make_pair(thisNum, i));
                cntM.insert(make_pair(thisNum, 1));
            }else{
                eM[thisNum] = i;
                cntM[thisNum]++;
            }
            maxCnt = maxCnt<cntM[thisNum]?cntM[thisNum]:maxCnt;
        }
        unordered_map<int, int>::iterator it = cntM.begin();
        while(it!=cntM.end()){
            if(it->second==maxCnt){
                thisNum = it->first;
                ans = ans<(eM[thisNum]-sM[thisNum]+1)?ans:(eM[thisNum]-sM[thisNum]+1);
            }
            it++;
        }
        return ans;
    }
};