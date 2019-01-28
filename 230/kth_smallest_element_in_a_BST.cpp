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
private:
    int cnt, ans, target;
    void midOrder(TreeNode* T){
        if(cnt==target || !T) return;
        midOrder(T->left);
        if(cnt != target) {
            cnt++;
            ans = T->val;
        }
        midOrder(T->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ret;
        target = k;
        cnt = 0;
        midOrder(root);
        ret = ans;
        return ret;
    }
};