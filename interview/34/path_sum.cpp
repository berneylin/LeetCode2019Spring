#include <vector>
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
        vector<vector<int> > rtnVec;
        vector<int> tmpVec;
        dfs(root, sum, tmpVec, rtnVec);
        return rtnVec;
    }

    void dfs(TreeNode* node, int target, vector<int> &thisVec, vector<vector<int> > &ansVec) {
        if (!node) return;
        
        thisVec.push_back(node->val);
        if (node->val == target && !node->left && !node->right) {
            ansVec.push_back(thisVec);
        }
        dfs(node->left, target - node->val, thisVec, ansVec);
        dfs(node->right, target - node->val, thisVec, ansVec);
        thisVec.pop_back();
    }
};