struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy, *end = dummy;
        while(pre){
            for(int i=0; i<k; i++){
                if(!end) break;
                end = end->next;
            }
            if(!end) break;
            // 对(pre, end] 翻转
            ListNode *next = pre->next;
            ListNode *ptr = pre->next;
            pre->next = end;
            while(ptr!=end){
                // 将ptr用头插法插入到end的后面
                ListNode *tmp = ptr->next;
                ptr->next = end->next;
                end->next = ptr;
                ptr = tmp;
            }
            pre = next;
            end = next;
        }
        return dummy->next;
    }
};