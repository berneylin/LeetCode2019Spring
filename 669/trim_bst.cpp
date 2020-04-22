struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root) return NULL;
        int &rootVal = root->val;
        if(rootVal<L){
            return trimBST(root->right, L, R);
        }else if(rootVal>R){
            return trimBST(root->left, L, R);
        }else{
            TreeNode* left = trimBST(root->left, L, R);
            TreeNode* right = trimBST(root->right, L, R);
            root->left = left;
            root->right = right;
            return root;
        }
    }
};