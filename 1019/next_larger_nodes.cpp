#include<stack>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        if(!head) return {};
        int listLength = 0;
        ListNode *ptr = head;
        while(ptr){
            listLength++;
            ptr = ptr->next;
        }
        vector<int> ansVec(listLength, 0);
        ptr = head;
        stack<pair<int, int> > tmpS;  // 记录<node->val, node_index>
        int idx = 0;
        while(ptr){
            while((!tmpS.empty()) && tmpS.top().first < ptr->val){
                ansVec[tmpS.top().second] = ptr->val;
                tmpS.pop();
            }

            tmpS.push({ptr->val, idx});
            ptr = ptr->next;
            idx++;
        }

        return ansVec;
    }
};

// 输入：[1,7,5,1,9,2,5,1]
// 输出：[7,9,9,9,0,5,0,0]