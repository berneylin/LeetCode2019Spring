struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return NULL;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy, *slow = dummy;
        while(fast && n--){
            fast = fast->next;
        }

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        // delete the next node of slow node
        ListNode *tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        
        return dummy->next;
    }
};