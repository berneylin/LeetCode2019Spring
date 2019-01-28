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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre = head;
        for(int i=0;i<n;i++) pre = pre->next;
        ListNode* post = head;
        if(!pre){
            head = head->next;
            delete post;
        }else{
            while(pre->next){
            pre = pre->next;
            post = post->next;
            }
            pre = post->next;
            post->next = post->next->next;
            delete pre;
        }
        return head;
    }
};