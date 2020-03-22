struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* tmpNode = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(tmpNode);
        return root;
    }
};