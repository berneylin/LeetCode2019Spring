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
    ListNode* partition(ListNode* head, int x) {
        ListNode* p = head;
        ListNode *ltPart = nullptr;  // lt: less than
        ListNode *ltPartHead = ltPart;
        ListNode *gePart = nullptr;  // ge: greater or equal
        ListNode *gePartHead = gePart;

        while(p){
            if(p->val < x){
                if(ltPartHead){
                    ltPart->next = p;
                    ltPart = p;
                }else{
                    ltPart = p;
                    ltPartHead = ltPart;
                }
            }else{
                if(gePartHead){
                    gePart->next = p;
                    gePart = p;
                }else{
                    gePart = p;
                    gePartHead = gePart;
                }
            }
            p = p->next;
        }
        if(gePart) gePart->next = nullptr;
        if(!ltPart) return gePartHead;
        else ltPart->next = gePartHead;
        
        return ltPartHead;
    }
};