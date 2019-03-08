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
    inline int max(int a, int b){
        return a>b?a:b;
    }
    inline int absMinus(int a, int b){
        return a>b?a-b:b-a;
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return isBalanced(root->left) && isBalanced(root->right) && (absMinus(heightOfTree(root->left), heightOfTree(root->right))<=1);
    }
    
    int heightOfTree(TreeNode* T) {
        if(!T) return 0;
        return max(heightOfTree(T->left), heightOfTree(T->right))+1;
    }
};