#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ansVec;
        vector<int> tmpVec;
        dfs(ansVec, candidates, 0, tmpVec, target);
        return ansVec;
    }

    void dfs(vector<vector<int> > &ansVec, vector<int> &candidates, int startIdx, vector<int> &tmpVec, int target){
        if(target==0){
            ansVec.push_back(tmpVec);
            return;
        }
        if(startIdx==candidates.size() || target<0)
            return;

        for(int i=startIdx; i<candidates.size(); i++){
            if(i>startIdx && candidates[i-1] == candidates[i]){
                continue;
            }
            tmpVec.push_back(candidates[i]);
            dfs(ansVec, candidates, i+1, tmpVec, target-candidates[i]);
            tmpVec.pop_back();
        }
    }

};