struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int listLen = 0;
        ListNode* ptr = head;
        while(ptr){
            ptr = ptr->next;
            listLen++;
        }

        k %= listLen;
        if(k==0) return head;
        ptr = head;
        for(int i=1; i<listLen-k; i++) ptr=ptr->next;
        
        // 此时ptr指向新的头结点的前一个
        ListNode* newHead = ptr->next;
        ptr->next = nullptr;

        ptr = newHead;
        while(ptr->next) ptr=ptr->next;
        ptr->next = head;

        return newHead;
    }
};