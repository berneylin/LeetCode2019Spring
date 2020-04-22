#include<vector>
using namespace std;


class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        if(graph.empty()) return {};
        vector<bool> isSafe(graph.size(), true);
        vector<int> tmpVec;
        for(int i=0; i<graph.size(); i++){
            if(isSafe[i]==false) continue;
            dfs(isSafe, graph, i, tmpVec);
        }
        vector<int> ansVec;
        for(int i=0; i<graph.size(); i++){
            if(isSafe[i]) ansVec.push_back(i);
        }
        return ansVec;
    }

    void dfs(vector<bool> &isSafe, vector<vector<int> > &graph, int startIdx, vector<int> &tmpVec){
        if(isSafe[startIdx]==false) return;

        if(!tmpVec.empty() && find(tmpVec.begin(), tmpVec.end(), startIdx)!=tmpVec.end()){
            // 说明当前路径存在一个环，环上所有的结点都不安全
            for(const int &nodeIdx: tmpVec){
                isSafe[nodeIdx] = false;
            }
            return;
        }


        tmpVec.push_back(startIdx);
        for(const int &targetIdx: graph[startIdx]){
            if(isSafe[targetIdx]==false){
                // 目标点不安全了，当前点也不安全
                isSafe[startIdx] = false;
                break;
            }
            dfs(isSafe, graph, targetIdx, tmpVec);
            if(isSafe[startIdx]==false){
                // 如果当前选择的路径存在一个环（即起点已经不安全了，剪枝）
                break;
            }
        }

        tmpVec.pop_back();
    }
};