#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int> > childMap;
        for(int i=0; i<manager.size(); i++){
            if(i==headID || informTime[i]==0) continue;
            childMap[manager[i]].push_back(i);
        }
        return dfs(headID, manager, informTime, childMap);
    }

    int dfs(int rootID, vector<int>& manager, vector<int>& informTime, unordered_map<int, vector<int>> &childMap){
        if(informTime[rootID]==0)
            return 0;
        
        int subTime = 0;
        for(int i=0; i<childMap[rootID].size(); i++){
            int tmp = dfs(childMap[rootID][i], manager, informTime, childMap);
            if(tmp>subTime) subTime = tmp;
        }
        return subTime+informTime[rootID];
    }
};