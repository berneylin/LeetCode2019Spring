#include<stack>
#include<vector>
using namespace std;


class LListNode{
public:
    int val;
    LListNode* next;
    LListNode(int _val){
        val = _val;
        next = NULL;
    }
    LListNode() {}
};


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
    vector<int> postorder(Node* root) {
        if(!root) return {};
        LListNode *dummy = new LListNode();
        dummy->next = NULL;
        stack<Node*> tmpS;
        tmpS.push(root);
        while(!tmpS.empty()){
            Node* node = tmpS.top();
            tmpS.pop();

            for(Node* &child: node->children){
                tmpS.push(child);
            }

            LListNode *newLNode = new LListNode(node->val);
            newLNode->next = dummy->next;
            dummy->next = newLNode;
        }
        vector<int> ansVec;
        LListNode *ptr = dummy->next;
        while(ptr){
            ansVec.push_back(ptr->val);
            LListNode* nextNode = ptr->next;
            delete ptr;
            ptr = nextNode;
        }
        delete dummy;
        return ansVec;
    }
};