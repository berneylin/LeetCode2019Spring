
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* convertBiNode(TreeNode* root) {
        inOrder(root);
        return ans;
    }
    
    void inOrder(TreeNode* node){
        if(!node) return NULL;
        inOrder(node->left);
        if(ans == NULL) ans = node;
        node->left = NULL;
        if(pre){
            pre->right = node;
        }
        pre = node;
        inOrder(node->right);
    }
private:
    TreeNode *ans = NULL;
    TreeNode *pre = NULL;
};