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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode(-1);  // return linked list pointer (head)
        ListNode* tail = ret;  // tail pointer of the return linked list for insert

        while(l1&&l2){
            if(l1->val<l2->val){ // insert l1->val
                tail->next = l1;
                tail = tail->next;
                l1 = l1->next;
            }else{ // insert l2->val
                tail->next = l2;
                tail = tail->next;
                l2 = l2->next;
            }
        }
        if(l1){
            tail->next = l1;
        }else if(l2){
            tail->next = l2;
        }
        return ret->next;
    }
};