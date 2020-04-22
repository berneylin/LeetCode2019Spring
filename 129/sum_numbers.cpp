struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int thisSum = 0, ans = 0;
        dfs(root, thisSum, ans);
        return ans;
    }

    void dfs(TreeNode* node, int &thisSum, int &ans){
        if(!node) return;

        thisSum *= 10;
        thisSum += node->val;
        

        if(!node->left && !node->right){
            ans += thisSum;
        }

        dfs(node->left, thisSum, ans);
        dfs(node->right, thisSum, ans);

        thisSum -= node->val;
        thisSum /= 10;
        return;
    }
};