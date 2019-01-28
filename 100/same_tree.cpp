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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ret = (p&&q)||(!p&&!q);
        if(ret&&p&&q){
            ret = p->val==q->val;
            if(ret){
                ret = isSameTree(p->left, q->left)&&isSameTree(p->right, q->right);
            }
        }
        return ret;
    }
};