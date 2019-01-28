/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=0, lenB=0;  // the length of list A and B, respectively
        ListNode* p = headA;
        ListNode* ret = nullptr;

        // traverse to obtain the length of both lists
        while(p){
            p = p->next;
            lenA++;
        }
        p = headB;
        while(p){
            p = p->next;
            lenB++;
        }
        int delta = lenA<lenB?lenB-lenA:lenA-lenB;

        if(lenA<lenB){  // uniform handle: make listA always the longer one
            // swap
            p = headA;
            headA = headB;
            headB = p;
        }
        p = headA;
        ListNode* q = headB;
        while(delta--){
            p = p->next;
        }

        while(p){
            if(p==q){
                ret = p;
                break;
            }
            p = p->next;
            q = q->next;
        }
        return ret;
    }
};