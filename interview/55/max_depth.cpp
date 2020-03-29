struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);
        return lDepth>rDepth?lDepth+1:rDepth+1;
    }
};