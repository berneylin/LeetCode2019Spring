#include<string>
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
    string smallestFromLeaf(TreeNode* root) {
        if(!root) return "";
        string ans = "";
        string tmpStr = "";
        dfs(root, tmpStr, ans);
        return ans;
    }

    void dfs(TreeNode *node, string &tmpStr, string &ans){
        if(!node) return;
        tmpStr.push_back('a'+node->val);
        if(!node->left && !node->right){
            string revStr = tmpStr;
            reverse(revStr.begin(), revStr.end());
            if(ans.empty()) ans = revStr;
            else if(revStr<ans) ans = revStr;
        }
        dfs(node->left, tmpStr, ans);
        dfs(node->right, tmpStr, ans);
        tmpStr.pop_back();
    }
};