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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return constructTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

    TreeNode* constructTree(const vector<int> &preOrder, int pl, int pr, const vector<int> &inOrder, int il, int ir) {
        if(pl>pr || il>ir){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preOrder[pl]);
        for(int i=0;i<ir;i++){
            if(preOrder[pl]==inOrder[i]){
                root->left = constructTree(preOrder, pl+1, pl+i-il, inOrder, il, i-1);
                root->right = constructTree(preOrder, pl+i-il+1, pr, inOrder, i+1, ir);
            }
        }
        return root;
    }




};