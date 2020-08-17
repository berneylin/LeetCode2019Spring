struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* invLeft = invertTree(root->left);
        TreeNode* invRight = invertTree(root->right);
        root->right = invLeft;
        root->left = invRight;
        return root;
    }
};