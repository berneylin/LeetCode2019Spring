#include<vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> rtnV;
        while(head){
            rtnV.push_back(head->val);
            head = head->next;
        }
        for(int i=0; i<rtnV.size()/2; i++){
            int tmp = rtnV[i];
            rtnV[i] = rtnV[rtnV.size() - i - 1];
            rtnV[rtnV.size() - i - 1] = tmp;
        }
        return rtnV;
    }
};