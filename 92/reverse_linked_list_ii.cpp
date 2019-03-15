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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || m==n) return head;
        ListNode* ansNode;
        if(m==1){
            ListNode* insertHead = head, *p = head->next, *insertTail = head;
            for(int i=1;i<=n-m;i++){
                ListNode* tmp = p->next;
                p->next = insertHead;
                insertHead = p;
                p = tmp;
            }
            insertTail->next = p;
            ansNode = insertHead;
        }else{
            ListNode* p = nullptr;
            for(int i=1;i<=m-1;i++){
                if(i==1) p = head;
                else p = p->next;
            }// 此时p指向第m-1个结点
            ListNode* insertHead = p, *insertTail = p->next;
            p = p->next; // 指向第m个结点
            for(int i=1;i<=n-m+1;i++){
                ListNode* tmp = p->next;
                p->next = insertHead->next;
                insertHead->next = p;
                p = tmp;
            }
            insertTail->next = p;
            ansNode = head;
        }
        return ansNode;
    }
};