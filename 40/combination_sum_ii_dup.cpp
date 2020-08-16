#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>　ansVec;
        if(candidates.empty() || target<=0) return ansVec;
        
        vector<int> tmpVec;
        int tmpSum = 0;

        sort(candidates.begin(), candidates.end());
        dfs(candidates, tmpVec, ansVec, 0, tmpSum, target);

        return ansVec;
    }

    void dfs(vector<int> &candidates, vector<int> &curCandidates, 
             vector<vector<int> > &ansVec, int startIdx, 
             int &currentSum, const int &target)
    {
        if(currentSum==target) ansVec.push_back(curCandidates);
        if(startIdx>=candidates.size() || currentSum>=target) return;

        for(int i=startIdx; i<candidates.size(); i++){
            if(i>startIdx && candidates[i-1] == candidates[i]) continue;
            curCandidates.push_back(candidates[i]);
            currentSum += candidates[i];
            dfs(candidates, curCandidates, ansVec, i+1, currentSum, target);
            currentSum -= candidates[i];
            curCandidates.pop_back();
        }
    }
};