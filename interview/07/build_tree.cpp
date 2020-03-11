#include<vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* build(vector<int> &preorder, vector<int> &inorder, int rootPreIdx, int inIdxStart, int inIdxEnd) {
        if (rootPreIdx >= preorder.size() || inIdxStart > inIdxEnd)
            return NULL;
        int rootInIdx = 0;
        for (int i = inIdxStart; i <= inIdxEnd; i++){
            if (inorder[i] == preorder[rootPreIdx]) {
                rootInIdx = i;
                break;
            }
        }
        TreeNode* rtnNode = new TreeNode(preorder[rootPreIdx]);
        rtnNode->left = build(preorder, inorder, rootPreIdx+1, inIdxStart, rootInIdx-1);
        rtnNode->right = build(preorder, inorder, rootPreIdx+rootInIdx-inIdxStart+1, rootInIdx+1, inIdxEnd);
        return rtnNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, 0, inorder.size()-1);
    }
};