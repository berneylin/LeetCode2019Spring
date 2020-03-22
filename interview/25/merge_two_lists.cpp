struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *a = l1, *b = l2;
        if(!a && b) return b;
        if(!b && a) return a;
        if(!a && !b) return nullptr;

        if(a->val > b->val) {
            a = l2;
            b = l1;
        }
        ListNode *ret = a;
        a = a->next;
        ListNode *retTail = ret;
        while(a && b) {
            if (a->val <= b->val) {
                retTail->next = a;
                retTail = retTail->next;
                a = a->next;
            } else {
                retTail->next = b;
                retTail = retTail->next;
                b = b->next;
            }
        }

        while(a) {
            retTail->next = a;
            retTail = retTail->next;
            a = a->next;
        }

        while(b) {
            retTail->next = b;
            retTail = retTail->next;
            b = b->next;
        }

        return ret;
    }
};