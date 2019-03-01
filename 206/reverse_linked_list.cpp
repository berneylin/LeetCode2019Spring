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
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = head, *tmp;
        if(!pre) return head;
        while(head->next){
            head = head->next;
        }
        while(pre!=head){
            tmp = pre->next;  // record raw next pointer
            pre->next = head->next;  // update the next pointer info.
            head->next = pre;  // insert pre node after the head pointer
            pre = tmp;
        }
        return head;
    }
};