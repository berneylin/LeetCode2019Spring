/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* cur = head, *pre = head;
        while(cur)
        {
            if(cur->val < x){
                int tmp = cur->val;
                cur->val = pre->val;
                pre->val = tmp;
                pre = pre->next;
            }
            cur = cur->next;
        }
        return head;
    }
};