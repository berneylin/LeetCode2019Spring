#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > rtnVec;
        queue<TreeNode*> tmpQueue;
        if(root) tmpQueue.push(root);
        while(!tmpQueue.empty()) {
            queue<TreeNode*> nextLevelQueue;
            vector<int> thisLevelVals;
            while(!tmpQueue.empty()){
                TreeNode* thisNode = tmpQueue.front();
                tmpQueue.pop();
                thisLevelVals.push_back(thisNode->val);
                if(thisNode->left) nextLevelQueue.push(thisNode->left);
                if(thisNode->right) nextLevelQueue.push(thisNode->right);
            }
            tmpQueue = nextLevelQueue;
            rtnVec.push_back(thisLevelVals);
        }
        return rtnVec;
    }
};