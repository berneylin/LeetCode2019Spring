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
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        inOrder(root);
        return ans;
    }
    void inOrder(TreeNode* T){
        if(!T) return;
        inOrder(T->left);
        ans.push_back(T->val);
        inOrder(T->right);
    }
};