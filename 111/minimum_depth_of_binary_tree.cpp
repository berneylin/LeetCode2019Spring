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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int ans = 0x7FFFFFFF;
        traverse(root, ans, 1);
        return ans;
    }

    void traverse(TreeNode* T, int &ans, int depth){
        if(!T||depth>ans) return;
        if(!T->left&&!T->right) ans = ans>depth?depth:ans;
        traverse(T->left, ans, depth+1);
        traverse(T->right, ans, depth+1);
    }
};