class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ret;
        vector<int> tmp;
        int thisSum = 0;
        int numsSize = candidates.size();
        int eachCnt[numsSize];
        memset(eachCnt, 0, numsSize*sizeof(int));
        vector<int> toBeDecided;
        DFS(ret, 0, toBeDecided, target, candidates, 0);
        return ret;
    }


    void DFS(vector<vector<int> > &ans, int thisSum, vector<int> &toBeDecided, const int &target, const vector<int>& can, int index){
        int cSize = can.size();
        for(int i=index;i<cSize;i++){
            if(can[i]+thisSum>target){
                continue;
            }else{
                toBeDecided.push_back(can[i]);
                if(can[i]+thisSum==target){
                    ans.push_back(toBeDecided);
                }else{
                    thisSum += can[i];
                    DFS(ans, thisSum, toBeDecided, target, can, i);
                    thisSum -= can[i];
                }
                toBeDecided.pop_back();
            }
        }
    }
};