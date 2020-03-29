struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mHead;
    Solution(ListNode* head) {
        mHead = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int nodeCnt = 0;
        ListNode *selectNode;

        ListNode *ptr = mHead;

        while(ptr){
            nodeCnt++;
            if(rand()%nodeCnt == 0) selectNode = ptr;
            ptr = ptr->next;
        }

        return selectNode->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */