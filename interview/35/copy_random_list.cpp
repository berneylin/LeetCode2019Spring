class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        // 1. 原地复制每个节点
        Node *ptr = head;
        while(ptr) {
            Node* copyNode = new Node(ptr->val);
            copyNode->next = ptr->next;
            ptr->next = copyNode;
            ptr = copyNode->next;
        }

        // 2. 给每个复制后的节点确定random指向的位置
        ptr = head;
        while(ptr) {
            ptr->next->random = ptr->random?ptr->random->next:nullptr;
            ptr = ptr->next->next;
        }

        // 3. 将原始链表与复制后的链表分开
        ptr = head;
        Node* newHead = head->next, *ptrCopy = head->next;
        while(ptr) {
            ptr->next = ptr->next->next;
            ptrCopy->next = ptrCopy->next?ptrCopy->next->next:nullptr;
            ptr = ptr->next;
            ptrCopy = ptrCopy->next;
        }
        return newHead;
    }
};