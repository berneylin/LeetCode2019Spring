#include<queue>
#include<vector>
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
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> Q;
        vector<vector<int> > res;
        if(root) Q.push(root);
        while(!Q.empty()) {
            vector<int> tmp;
            queue<TreeNode*> newQ;
            while(!Q.empty()) {
                tmp.push_back(Q.front()->val);
                if(Q.front()->left) newQ.push(Q.front()->left);
                if(Q.front()->right) newQ.push(Q.front()->right);
                Q.pop();
            }
            res.insert(res.begin(), tmp);
            Q = newQ;
        }
        return res;
    }
};