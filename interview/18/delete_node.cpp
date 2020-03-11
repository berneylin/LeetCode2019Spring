class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(!head) return nullptr;
        if(head->val == val) return head->next;
        ListNode* lhs = head, *rhs = head->next;
        while(rhs){
            if(rhs->val == val){
                lhs->next = rhs->next;
                break;
            }
            lhs = lhs->next;
            rhs = rhs->next;
        }
        return head;
    }
};