#include<vector>
#include<queue>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct tmpStruct
{
    bool operator() (ListNode* a, ListNode *b){
        return a->val > b->val;
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        priority_queue<ListNode*, vector<ListNode*>, tmpStruct> tmpQueue;
        for(int i=0; i<lists.size(); i++){
            if(lists[i]) tmpQueue.push(lists[i]);
        }

        while(!tmpQueue.empty()){
            ListNode* cur = tmpQueue.top();
            tmpQueue.pop();
            tail->next = cur;
            tail = tail->next;
            cur = cur->next;
            tail->next = NULL;
            if(cur) tmpQueue.push(cur);
        }

        return dummy->next;
    }
};