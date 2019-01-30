#include<stack>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> S;
        TreeNode* p = root;
        while(p||!S.empty()){
            // push all left nodes towards the most left child of current node p
            while(p){
                S.push(p);
                p=p->left;
            }
            if(!S.empty()){
                p = S.top();
                S.pop();
                ans.push_back(p->val);
                p = p->right;
            }
        }
        return ans;
    }
};