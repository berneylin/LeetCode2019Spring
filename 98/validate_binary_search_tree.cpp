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
    int pre;
    bool isFirst = true;
    bool isValid = true;
    bool isValidBST(TreeNode* root) {
        if(!root) return isValid;
        inOrder(root);
        return isValid;
    }

    void inOrder(TreeNode* T){
        if(isValid&&T){
            inOrder(T->left);
            if(isFirst){
                isFirst = false;
                pre = T->val;
            }else{
                if(T->val<=pre){
                    isValid = false;
                    return;
                }else{
                    pre = T->val;
                }
            }
            inOrder(T->right);
        }
    }

};