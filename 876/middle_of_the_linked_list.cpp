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
    ListNode* middleNode(ListNode* head) {
        ListNode* pre = head, *post = head;
        while(pre && pre->next){
            pre = pre->next->next;
            post = post->next;
        }
        return post;
    }
};