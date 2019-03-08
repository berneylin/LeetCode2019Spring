/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        traverse(ans, root, 0);
        return ans;
    }

    void traverse(vector<int> &ans, TreeNode* T, int level) {
        if(!T) return;
        if(level>=ans.size()) ans.push_back(T->val);
        else ans[level] = ans[level]>T->val?ans[level]:T->val;
        traverse(ans, T->left, level+1);
        traverse(ans, T->right, level+1);
    }
};