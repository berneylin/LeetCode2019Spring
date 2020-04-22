#include<vector>
using namespace std;


class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ansVec;
        dfs(root, ansVec);
        return ansVec;
    }

    void dfs(Node *node, vector<int> &ansVec){
        if(!node) return;
        ansVec.push_back(node->val);
        for(Node* child: node->children){
            dfs(child, ansVec);
        }
    }
};