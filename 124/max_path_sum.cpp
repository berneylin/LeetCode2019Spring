#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        postOrder(root, ans);
        return ans;
    }

    int postOrder(TreeNode* node, int &ans){
        if(!node) return 0;
        int leftMax, rightMax;
        leftMax = max(postOrder(node->left, ans), 0);
        rightMax = max(postOrder(node->right, ans), 0);

        ans = max(ans, node->val+leftMax+rightMax);
        return node->val+max(0, max(leftMax, rightMax));
    }
};