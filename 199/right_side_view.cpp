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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> tmpQ;
        tmpQ.push(root);
        vector<int> ansVec;
        while(!tmpQ.empty()){
            int levelSize = tmpQ.size();
            while(--levelSize){
                TreeNode* tmp = tmpQ.front();
                if(tmp->left) tmpQ.push(tmp->left);
                if(tmp->right) tmpQ.push(tmp->right);
                tmpQ.pop();
            }
            TreeNode* tmp = tmpQ.front();
            ansVec.push_back(tmp->val);
            if(tmp->left) tmpQ.push(tmp->left);
            if(tmp->right) tmpQ.push(tmp->right);
            tmpQ.pop();
        }
        return ansVec;
    }
};