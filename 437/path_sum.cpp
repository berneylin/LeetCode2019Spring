#include<unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int ans = 0;
        unordered_map<int, int> sumCntMap;
        sumCntMap[0] = 1;
        int thisSum = 0;
        dfs(sumCntMap, root, sum, thisSum, ans);
        return ans;
    }

    void dfs(unordered_map<int, int> sumCntMap, TreeNode* node, const int &target, int &thisSum, int &ans){
        if(!node) return;
        thisSum += node->val;
        if(sumCntMap.find(thisSum-target)!=sumCntMap.end()){
            ans += sumCntMap[thisSum-target];
        }
        if(sumCntMap.find(thisSum)==sumCntMap.end()) sumCntMap[thisSum] = 0;
        sumCntMap[thisSum]++;
        dfs(sumCntMap, node->left, target, thisSum, ans);
        dfs(sumCntMap, node->right, target, thisSum, ans);
        sumCntMap[thisSum]--;
        thisSum -= node->val;
    }
};