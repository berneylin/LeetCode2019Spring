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
    int findSecondMinimumValue(TreeNode* root) {
        int firstMin = root->val;
        int ret = -1;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            TreeNode* tmp = Q.front();
            Q.pop();
            if(tmp->val!=firstMin){
                if (ret==-1)
                    ret = tmp->val;  // update the first value
                else if(tmp->val<ret){
                    ret = tmp->val;
                    if(tmp->left){
                        Q.push(tmp->left);
                        Q.push(tmp->right);
                    }
                }
            }else{
                if(tmp->left){
                    Q.push(tmp->left);
                    Q.push(tmp->right);
                }
            }
        }
        return ret;
    }
};