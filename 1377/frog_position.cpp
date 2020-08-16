#include<unordered_map>
#include<vector>
using namespace std;


class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if(n==1) return 1.0;
        vector<double> prob(n, 0);
        vector<int> depth(n, 0);
        unordered_map<int, vector<int> > childMap;
        unordered_map<int, int> fatherMap;

        for(const auto& edge: edges){
            childMap[edge[0]-1].push_back(edge[1]-1);
            fatherMap[edge[1]-1] = edge[0]-1;
        }

        vector<int> targetPath;
        int nodeIdx = target-1;
        targetPath.push_back(nodeIdx);
        while(fatherMap.find(nodeIdx)!=fatherMap.end()){
            targetPath.push_back(fatherMap[nodeIdx]);
            nodeIdx = fatherMap[nodeIdx];
        }

        int targetDepth = targetPath.size();
        if(targetDepth<=t && childMap.find(target)!=childMap.end()){
            return 0.0;
        }

        // 一定有非0解
        double ans = 1.0;
        for(int i=targetPath.size()-1; i>0; i++){
            int curChildNum = childMap[targetPath[i]].size();
            ans *= (double)(1.0 / curChildNum);
        }
        return ans;

    }

};