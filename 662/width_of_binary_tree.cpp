struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root, 0, 0);
        return maxWidth;
    }
    void dfs(TreeNode* node, int currDepth, unsigned long long currIdx){
        if(!node) return;

        if(currDepth==leftIndices.size()){
            leftIndices.push_back(currIdx);
        }

        int currWidth = currIdx - leftIndices[currDepth] + 1;
        if(currWidth>maxWidth){
            maxWidth = currWidth;
        }

        dfs(node->left, currDepth+1, currIdx*2);
        dfs(node->right, currDepth+1, currIdx*2+1);
    }
private:
    unsigned long long maxWidth = 0;
    vector<unsigned long long> leftIndices;
};