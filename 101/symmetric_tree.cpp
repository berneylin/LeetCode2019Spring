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
    bool isMirror = true;


    bool isSymmetric(TreeNode* root) {
        order(root, root);
        return isMirror;
    }

    void order(TreeNode* nodeL, TreeNode* nodeR){
        if(!isMirror) return;
        if(!nodeL||!nodeR){
            if(!nodeL&&!nodeR);
            else isMirror = false;
        }
        else{
            if(nodeL->val!=nodeR->val) isMirror=false;
            else{
                order(nodeL->left, nodeR->right);
                order(nodeL->right, nodeR->left);
            }
        }
    }
};