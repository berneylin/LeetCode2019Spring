#include<queue>
using namespace std;

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
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(!root) return res;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            queue<TreeNode*> nextQ;
            vector<int> elem;
            while(!Q.empty()){
                TreeNode* tmp = Q.front();
                Q.pop();
                elem.push_back(tmp->val);
                if(tmp->left) nextQ.push(tmp->left);
                if(tmp->right) nextQ.push(tmp->right);
            }
            ans.push_back(elem);
            Q = nextQ;
        }
        return res;
    }
};