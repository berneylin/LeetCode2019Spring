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
    int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        vector<int> tmpVec;
        dfs(root, tmpVec, ans);
        return ans;
    }

    void dfs(TreeNode *node, vector<int> &tmpVec, int &ans){
        if(!node) return;
        tmpVec.push_back(node->val);
        if(!node->left && !node->right){
            int base = 1;
            int curNum = 0;
            for(int i=tmpVec.size()-1; i>=0; i--){
                curNum += (base * tmpVec[i]);
                base <<= 1;
            }

            ans = (ans % _mode + curNum % _mode) % _mode;
        }
        dfs(node->left, tmpVec, ans);
        dfs(node->right, tmpVec, ans);
        tmpVec.pop_back();
        return;
    }
private:
    const int _mode = 1e9+7;
    
};