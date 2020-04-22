struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return NULL;
        ListNode* rtnHead = head, *sortedTail = head, *curr = head->next;
        sortedTail->next = NULL;
        while(curr){
            if(curr->val >= sortedTail->val){
                sortedTail->next = curr;
                sortedTail = curr;
                curr = curr->next;
                sortedTail->next = NULL;
            }
            else{
                if(curr->val <= rtnHead->val){
                    ListNode* tmp = curr->next;
                    curr->next = rtnHead;
                    rtnHead = curr;
                    curr = tmp;
                }else
                {
                    ListNode *ptr = rtnHead;
                    while(ptr->next->val < curr->val) ptr = ptr->next;
                    ListNode *tmp = curr->next;
                    curr->next = ptr->next;
                    ptr->next = curr;
                    curr = tmp;
                }
            }
        }
        return rtnHead;

    }
};