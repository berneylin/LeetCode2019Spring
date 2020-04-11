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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = 0x80000000;
        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);
        postOrder(root, ans);
        return ans;
    }

    int postOrder(TreeNode *node, int &ans){
        if(!node) return 0;
        int leftD = postOrder(node->left, ans);
        int rightD = postOrder(node->right, ans);

        ans = max(ans, leftD+rightD);
        return max(leftD, rightD) + 1;
    }
};