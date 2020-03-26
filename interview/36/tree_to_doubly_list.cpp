class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) {
            return nullptr;
        }
        Node *smallestNode = root;
        while(smallestNode->left) {
            smallestNode = smallestNode->left;
        }
        Node *biggestNode = root;
        while(biggestNode->right) {
            biggestNode = biggestNode->right;
        }
        Node *pre = nullptr;
        process(root, pre);
        smallestNode->left = biggestNode;
        biggestNode->right = smallestNode;
        return smallestNode;
    }

    void process(Node* node, Node* &preNode) {
        if(!node) return;
        process(node->left, preNode);
        node->left = preNode;
        if(preNode) {
            preNode->right = node;
        }
        preNode = node;
        process(node->right, preNode);
    }
};