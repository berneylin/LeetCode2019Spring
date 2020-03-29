#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        stack<TreeNode*> tmpStack;
        if(!root) return 0;
        while(root){
            tmpStack.push(root);
            root = root->right;
        }
        int ans = 0;
        while(k--) {
            TreeNode* thisNode = tmpStack.top();
            tmpStack.pop();
            ans = thisNode->val;
            root = thisNode->left;
            while(root){
                tmpStack.push(root);
                root = root->right;
            }
        }
    }
};