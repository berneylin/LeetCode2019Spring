
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;

        ListNode *oddTail = head, *evenHead = head->next, *evenTail = head->next;

        while(evenTail){
            oddTail->next = evenTail->next;
            evenTail->next = evenTail->next?evenTail->next->next:nullptr;
            oddTail = oddTail->next;
            evenTail = evenTail->next;
        }

        oddTail->next = evenHead;

        return head;
    }
};