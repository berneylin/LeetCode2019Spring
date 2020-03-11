struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* retHead = head;
        head = head->next;
        retHead->next = nullptr;
        while(head){
            ListNode *tmp = head->next;
            head->next = retHead;
            retHead = head;
            head = tmp;
        }
        return retHead;
    }
};