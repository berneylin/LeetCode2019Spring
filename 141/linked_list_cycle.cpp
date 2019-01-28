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
    bool hasCycle(ListNode *head) {
        bool isHasCycle = false;
        if(!head) return isHasCycle;
        ListNode* fast = head;
        ListNode* slow = head;  // two pointers method
        while(fast&&fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow){
                isHasCycle = true;
                break;
            }
        }

        return isHasCycle;
    }
};