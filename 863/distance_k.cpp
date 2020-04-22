#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(!root || !target) return {};
        if(K==0) return {target->val};
        // 二叉树转图
        unordered_map<TreeNode*, TreeNode*> parentMap;
        parentMap[root] = NULL;
        preOrder(parentMap, root);

        //dfs
        vector<int> ansVec;
        unordered_set<TreeNode*> visited;
        dfs(parentMap, 0, K, ansVec, target, visited);
        return ansVec;
    }
    
    void preOrder(unordered_map<TreeNode*, TreeNode*> &parentMap, TreeNode* node){
        if(!node) return;
        if(node->left) parentMap[node->left] = node;
        if(node->right) parentMap[node->right] = node;
        preOrder(parentMap, node->left);
        preOrder(parentMap, node->right);
    }

    void dfs(unordered_map<TreeNode*, TreeNode*> &parentMap, int thisDist, const int &K, vector<int> &ansVec, TreeNode* node, unordered_set<TreeNode*> &visited){
        if(thisDist==K) {
            ansVec.push_back(node->val);
            return;
        }
        visited.insert(node);
        if(node->left && visited.find(node->left)==visited.end())
            dfs(parentMap, thisDist+1, K, ansVec, node->left, visited);
        if(node->right && visited.find(node->right)==visited.end())
            dfs(parentMap, thisDist+1, K, ansVec, node->right, visited);
        if(parentMap[node] && visited.find(parentMap[node])==visited.end())
            dfs(parentMap, thisDist+1, K, ansVec, parentMap[node], visited);
    }
};