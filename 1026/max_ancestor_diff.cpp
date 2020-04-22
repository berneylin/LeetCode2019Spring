#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        _ans = 0x80000000;
        _max = 0x80000000;
        _min = 0x7FFFFFFF;
        dfs(root);
        return _ans;
    }

    void dfs(TreeNode *node){
        if(!node) return;
        int preMax = _max;
        int preMin = _min;
        _max = max(node->val, _max);
        _min = min(node->val, _min);
        _ans = max(_max - _min, _ans);

        dfs(node->left);
        dfs(node->right);

        _max = preMax;
        _min = preMin;
    }
private:
    int _ans, _max, _min;
};