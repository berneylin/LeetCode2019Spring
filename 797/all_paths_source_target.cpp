#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        if(graph.empty()) return {};
        int graphSize = graph.size();

        vector<int> tmpVec = {0};
        vector<vector<int> > ansVec;
        dfs(tmpVec, ansVec, graph, 0);
        return ansVec;
    }

    void dfs(vector<int> &tmpVec, vector<vector<int> > &ansVec, vector<vector<int> > &graph, int thisNodeIdx){
        if(thisNodeIdx==graph.size()-1){
            ansVec.push_back(tmpVec);
            return;
        }
        vector<int> &thisHeadTo = graph[thisNodeIdx];
        for(const int &targetNodeIdx: thisHeadTo){
            tmpVec.push_back(targetNodeIdx);
            dfs(tmpVec, ansVec, graph, targetNodeIdx);
            tmpVec.pop_back();
        }
    }
};

// 输入: [[1,2], [3], [3], []] 
// 输出: [[0,1,3],[0,2,3]] 