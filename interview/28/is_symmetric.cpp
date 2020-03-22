struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return recur(root, root);
    }

    bool recur(TreeNode* a, TreeNode* b) {
        if(!a && !b) return true;
        if((!a && b) || (a && !b)) return false;
        if(a->val != b->val) return false;
        return recur(a->left, b->right) && recur(a->right, b->left);
    }
    
};