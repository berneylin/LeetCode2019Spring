struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode *ptr = root;
        while(ptr){
            if(ptr->left) {
                TreeNode *preRight = ptr->right;
                ptr->right = ptr->left;
                ptr->left = nullptr;
                if(preRight){
                    TreeNode *tmpNode = ptr;
                    while(tmpNode->right) tmpNode = tmpNode->right;
                    tmpNode->right = preRight;
                }
            }
            ptr = ptr->right;
        }
    }
};