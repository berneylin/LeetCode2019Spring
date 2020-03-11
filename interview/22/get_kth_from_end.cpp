struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(k<=0) return nullptr;
        int tmp = k;
        ListNode *pre = head, *post = head;
        while(post && tmp){
            post = post->next;
            tmp --;
        }
        if(tmp!=0) return nullptr;
        while(post){
            pre = pre->next;
            post = post->next;
        }
        return pre;
    }
};