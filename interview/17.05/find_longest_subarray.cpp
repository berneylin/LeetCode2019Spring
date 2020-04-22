#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    inline bool isNum(string str){
        return str[0] >= '0' && str[0] <= '9';
    }
    vector<string> findLongestSubarray(vector<string>& array) {
        if(array.empty()) return {};

        int sum[array.size()];
        for(int i=0; i<array.size(); i++){
            if(i==0) sum[0] = isNum(array[i])?1:-1;
            else sum[i] = sum[i-1] + (isNum(array[i])?1:-1);
        }

        unordered_map<int, int> tmpM;
        int maxLen = -1, lhs, rhs;
        for(int i=0; i<array.size(); i++){
            if(sum[i]==0){
                int thisLen = i+1;
                if(thisLen>maxLen){
                    maxLen = thisLen;
                    lhs = 0;
                    rhs = i;
                }
            } 
            else{
                if(tmpM.find(sum[i])==tmpM.end()) tmpM[sum[i]] = i;
                else {
                    int thisLen = i-tmpM[sum[i]];
                    if(thisLen>maxLen){
                        maxLen = thisLen;
                        lhs = tmpM[sum[i]] + 1;
                        rhs = i;
                    }
                }
            }
        }
        if (maxLen==-1) return {};
        vector<string> ansVec;
        while(lhs<=rhs) ansVec.push_back(array[lhs++]);
        return ansVec;
    }
};