
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptrA = headA, *ptrB = headB;
        while (ptrA!=ptrB) {
            ptrA = ptrA?ptrA->next:headB;
            ptrB = ptrB?ptrB->next:headA;
        }
        return ptrA;

    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return nullptr;

        int lenA = 0, lenB = 0;
        ListNode *ptrA = headA, *ptrB = headB;
        while(ptrA) {
            lenA++;
            ptrA = ptrA->next;
        }
        while(ptrB) {
            lenB++;
            ptrB = ptrB->next;
        }

        // 使A表总是不短于B表
        if (lenA<lenB) {
            ptrA = headA;
            headA = headB;
            headB = ptrA;
        }

        ptrA = headA;
        ptrB = headB;

        // 长的表先出发
        int diff = lenA - lenB;
        diff = diff < 0?-diff:diff;
        while(diff--) {
            ptrA = ptrA->next;
        }

        while(ptrA && ptrA!=ptrB){
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }

        return ptrA;

    }
};