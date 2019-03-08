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

    int diameterOfBinaryTree(TreeNode* root) {
        int maxLen = 0;
        traverse(maxLen, root);
        return maxLen;
    }

    void traverse(int &maxLen, TreeNode* T) {
        if(!T) return;
        maxLen = max(maxLen, heightOfTree(T->left)+heightOfTree(T->right)-2);
        traverse(maxLen, T->left);
        traverse(maxLen, T->right);
    }
    
    int heightOfTree(TreeNode* T) {
        if(!T) return 0;
        else return max(heightOfTree(T->left), heightOfTree(T->right)) + 1;
    }
};