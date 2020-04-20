#include<vector>
#include<string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string tmpStr = "";
        vector<string> ansVec;
        dfs(root, ansVec, tmpStr);
        return ansVec;
    }
    
    void dfs(TreeNode* node, vector<string> &ansVec, string &tmpStr){
        if(!node) return;
        string preStr = tmpStr;
        if(tmpStr.empty()) tmpStr += to_string(node->val);
        else tmpStr += "->" + to_string(node->val);
        if(!node->left && !node->right) ansVec.push_back(tmpStr);
        dfs(node->left, ansVec, tmpStr);
        dfs(node->right, ansVec, tmpStr);
        tmpStr = preStr;
    }
};