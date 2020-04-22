struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *fast = head, *slow = head, *pre = head;
        while(fast && fast->next){
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = NULL;
        ListNode* preHead = sortList(head);
        ListNode* postHead = sortList(slow);
       
        return mergeSortedList(preHead, postHead);
    }

    ListNode* mergeSortedList(ListNode *lhs, ListNode *rhs){
        if(!lhs) return rhs;
        if(!rhs) return lhs;

        if(lhs->val <= rhs->val){
            lhs->next = mergeSortedList(lhs->next, rhs);
            return lhs;
        }else{
            rhs->next = mergeSortedList(rhs->next, lhs);
            return rhs;
        }
    }
};