
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *ptrA = headA, *ptrB = headB;
        while(ptrA){
            lenA++;
            ptrA = ptrA->next;
        }
        while(ptrB){
            lenB++;
            ptrB = ptrB->next;
        }
        if(lenA<lenB) return getIntersectionNode(headB, headA);
        ptrA = headA;
        ptrB = headB;
        for(int idx=0; idx<lenA-lenB; idx++) ptrA = ptrA->next;

        while(ptrA){
            if(ptrA==ptrB) return ptrA;
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }

        return nullptr;
    }
};