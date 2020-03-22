#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> rtnVec;
        queue<TreeNode*> tmpQueue;
        if(!root) return rtnVec;
        tmpQueue.push(root);
        while(!tmpQueue.empty()) {
            TreeNode* thisNode = tmpQueue.front();
            tmpQueue.pop();
            rtnVec.push_back(thisNode->val);
            if(thisNode->left) tmpQueue.push(thisNode->left);
            if(thisNode->right) tmpQueue.push(thisNode->right);
        }
        return rtnVec;
    }
};