#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0;
        unordered_map<int, int> cntMap;
        for(const int &num: answers){
            if(cntMap.find(num+1)==cntMap.end() || cntMap[num+1]==0){
                ans += num+1;
                cntMap[num+1] = num+1;
            }
            cntMap[num+1]--;
        }
        return ans;
    }
};