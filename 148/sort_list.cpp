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
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next) return head;
        else{
            // 使用快慢指针法，找到链表的中间节点，以便进行归并划分
            ListNode* fast = head, *slow = head;
            while(fast->next && fast->next->next){
                fast = fast->next->next;
                slow = slow->next;
            }
            // 此时，slow指向的即为链表的中间(向下取整)节点
            ListNode* headOfListB = slow->next; // 后半部分链表的表头
            ListNode* headOfListA = head;  // 前半部分链表的表头，即为原表头
            slow->next = nullptr;  // 断开原先前半部分与后半部分的链接
            headOfListA = sortList(headOfListA);
            headOfListB = sortList(headOfListB);
            return mergeList(headOfListA, headOfListB);
        }
    }

    ListNode* mergeList(ListNode* headA, ListNode* headB) {
        if(!headA) return headB;
        if(!headB) return headA;
        ListNode* res, *p;
        if(headA->val<=headB->val){
            res = headA;
            headA = headA->next;
        }else{
            res = headB;
            headB = headB->next;
        }
        p = res;
        while(headA && headB) {
            if(headA->val<=headB->val){
                p->next = headA;
                headA = headA->next;
            }else{
                p->next = headB;
                headB = headB->next;
            }
            p = p->next;
        }
        if(headA){
            p->next = headA;
        }
        if(headB){
            p->next = headB;
        }
        return res;
    }
};