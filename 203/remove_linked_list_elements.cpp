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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* tmp;
        while(head && head->val == val){  // Firstly, remove all the target values one the head of the list
            tmp = head;
            head = head->next;
            delete tmp;
        }

        // Now the head pointer's value isn't target value in all conditions. (May be the list has been empty and the head pointer points to nullptr.)

        ListNode* pre, *post;
        pre = head;
        post = head;

        if(pre) pre = pre->next;  // `pre' is one position prior of `post'
        else return head;

        while(pre){
            if(pre->val==val){
                tmp = pre;
                post->next = pre->next;
                pre = pre->next;
                delete tmp;
            }else{
                pre = pre->next;
                post = post->next;
            }
        }
        return head;
    }
};