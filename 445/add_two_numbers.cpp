struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0, len2 = 0;
        ListNode* ptr = l1;
        while(ptr){
            len1++;
            ptr = ptr->next;
        }
        ptr = l2;
        while(ptr){
            len2++;
            ptr = ptr->next;
        }
        if(len1<len2){
            // 使l1一定比l2长
            int tmp = len1;
            len1 = len2;
            len2 = tmp;
            ListNode* tmpNode = l1;
            l1 = l2;
            l2 =tmpNode;
        }

        int zeroCnt = len1 - len2;
        while (zeroCnt--)
        {
            // 在l2前面补0
            ListNode* zeroNode = new ListNode(0);
            zeroNode->next = l2;
            l2 = zeroNode;
        }
        
        // 现在2个链表一样长了 递归处理
        int carry = 0;
        ListNode* rtnHead = recursion(l1, l2, carry);
        if(carry!=0){
            ListNode *carryNode = new ListNode(carry);
            carryNode->next = rtnHead;
            rtnHead = carryNode;
        }
        return rtnHead;
    }

    ListNode* recursion(ListNode *l1, ListNode *l2, int &carry){
        if(!l1) return NULL;
        ListNode* curNext = recursion(l1->next, l2->next, carry);
        int thisSum = l1->val + l2->val + carry;
        carry = thisSum / 10;
        thisSum %= 10;
        ListNode* newNode = new ListNode(thisSum);
        newNode->next = curNext;
        return newNode;
    }

};