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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* notDuplicate = head;
        ListNode* p = head;
        if(!notDuplicate) return head;
        while(p){
            if(p->next && p->val!=p->next->val){
                notDuplicate->val = p->val;
                notDuplicate = notDuplicate->next;
            }else if(!p->next){
                notDuplicate->val = p->val;
            }
            p = p->next;
        }
        ListNode* nodeNeedDel = notDuplicate->next;
        notDuplicate->next = nullptr;
        while(nodeNeedDel){
            ListNode* tmp = nodeNeedDel;
            nodeNeedDel = nodeNeedDel->next;
            delete tmp;
        }
        return head;
    }
};