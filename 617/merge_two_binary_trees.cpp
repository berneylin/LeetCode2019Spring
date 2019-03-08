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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1) return t2;
        if(!t2) return t1;
        t1->val += t2->val;
        merge(t1, t2);  // 在t1上合并2棵二叉树
        return t1;
    }

    void merge(TreeNode* t1, TreeNode* t2) {
        /* left child part */
        if(t1->left&&t2->left){
            t1->left->val += t2->left->val;
            merge(t1->left, t2->left);
        }
        else if(!t1->left&&t2->left) t1->left = t2->left;
        
        /* right child part */
        if(t1->right&&t2->right){
            t1->right->val += t2->right->val;
            merge(t1->right, t2->right);
        }
        else if(!t1->right&&t2->right) t1->right = t2->right;

    }
};