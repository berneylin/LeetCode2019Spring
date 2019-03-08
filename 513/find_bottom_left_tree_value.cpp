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
    int ansLevel;
    int ansVal;
    int findBottomLeftValue(TreeNode* root) {
        this->ansLevel = -1;
        traverse(root, 0);
        return this->ansVal;
    }

    void traverse(TreeNode* T, int level) {
        if(!T) return;
        traverse(T->left, level+1);
        if(level > this->ansLevel){
            this->ansLevel = level;
            this->ansVal = T->val;
        }
        traverse(T->right, level+1);
    }
};