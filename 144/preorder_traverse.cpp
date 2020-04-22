#include<vector>
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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*> tmpS;
        vector<int> ansVec;
        tmpS.push(root);
        while(!tmpS.empty()){
            TreeNode* node = tmpS.top();
            tmpS.pop();
            ansVec.push_back(node->val);
            if(node->right) tmpS.push(node->right);
            if(node->left) tmpS.push(node->left);
        }
        return ansVec;
    }
};