struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int lDepth = depth(root->left);
        if(lDepth==-1) return false;
        int rDepth = depth(root->right);
        if(rDepth==-1) return false;
        return !((lDepth-rDepth)>1 || (lDepth-rDepth)<-1);
    }

    int depth(TreeNode* node){
        if(!node) return 0;
        int lDepth = depth(node->left);
        if (lDepth==-1) return -1;
        int rDepth = depth(node->right);
        if (rDepth==-1) return -1;
        if(lDepth-rDepth>1 || lDepth-rDepth<-1) return -1;
        return lDepth>rDepth?lDepth+1:rDepth+1;
    }
};