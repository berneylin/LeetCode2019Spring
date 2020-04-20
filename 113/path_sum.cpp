#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        int thisSum = 0;
        vector<int> thisPath;
        vector<vector<int> > ansVec;
        dfs(root, ansVec, thisSum, sum, thisPath);
        return ansVec;
    }

    void dfs(TreeNode* node, vector<vector<int> > &ansVec, int &thisSum, const int &target, vector<int> &pathVec){
        if(!node) return;
        thisSum += node->val;
        pathVec.push_back(node->val);
        if(!node->left && !node->right && thisSum==target) ansVec.push_back(pathVec);
        dfs(node->left, ansVec, thisSum, target, pathVec);
        dfs(node->right, ansVec, thisSum, target, pathVec);
        pathVec.pop_back();
        thisSum -= node->val;
    }
};