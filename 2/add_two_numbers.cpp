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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ret = nullptr;  // declare the return list
        ListNode* tail = nullptr;
        while(l1&&l2){
            int currSum = l1->val + l2->val + carry;
            int insertNum = currSum % 10;
            carry = (currSum/10);

            ListNode* currNode = new ListNode(insertNum);
            if(ret == nullptr){
                ret = currNode;
                tail = ret;
            }else{
                tail->next = currNode;
                tail = tail->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){ // linked list one still remains elements
            int currSum = l1->val + carry;
            int insertNum = currSum % 10;
            carry = (currSum/10);
            ListNode* currNode = new ListNode(insertNum);
            if(ret==nullptr){
                ret = currNode;
                tail = ret;
            }else{
                tail->next = currNode;
                tail = tail->next;
            }
            l1 = l1->next;
        }

        while(l2){  // linked list two still remains elements
            int currSum = l2->val + carry;
            int insertNum = currSum % 10;
            carry = (currSum/10);
            ListNode* currNode = new ListNode(insertNum);
            if(ret==nullptr){
                ret = currNode;
                tail = ret;
            }else{
                tail->next = currNode;
                tail = tail->next;
            }
            l2 = l2->next;
        }
        
        if(carry){
            ListNode* currNode = new ListNode(carry);
            tail->next = currNode;
            tail = tail->next;
        }

        return ret;
    }
};