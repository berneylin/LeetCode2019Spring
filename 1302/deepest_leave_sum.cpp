struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return deepSum;
    }

    void dfs(TreeNode *node, int currDepth){
        if(!node) return;

        if(currDepth>maxDepth){
            maxDepth = currDepth;
            deepSum = 0;
        }

        if(currDepth==maxDepth){
            deepSum += node->val;
        }
        dfs(node->left, currDepth+1);
        dfs(node->right, currDepth+1);
    }

private:
    int maxDepth = 0;
    int deepSum = 0;
};