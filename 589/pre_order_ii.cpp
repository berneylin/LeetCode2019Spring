#include<vector>
#include<stack>
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
        if(!root) return ansVec;
        stack<Node*> tmpS;
        tmpS.push(root);
        while(!tmpS.empty()){
            Node* thisNode = tmpS.top();
            tmpS.pop();
            ansVec.push_back(thisNode->val);
            for(int i=thisNode->children.size()-1; i>=0; i--) 
                tmpS.push(thisNode->children[i]);
        }

        return ansVec;
    }

};