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
    int ansNum = 0;
    bool ansFlag = true;
    bool isUnivalTree(TreeNode* root) {
        this->ansFlag = true;
        this->ansNum = root?root->val:0;
        traverse(root);
        return ansFlag;
    }

    void traverse(TreeNode* T) {
        if(!T || !ansFlag) return;
        if(T->val!=ansNum) {
            this->ansFlag = false;
        }else{
            traverse(T->left);
            traverse(T->right);
        }
    }
};