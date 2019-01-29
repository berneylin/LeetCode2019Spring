#include<stack>
using namespace std;


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
    bool isPalindrome(ListNode* head) {
        bool ret = true;
        stack<int> S;
        ListNode *p = head;
        while(p){
            S.push(p->val);
            p = p->next;
        }
        p = head;
        while(p){
            if(S.top()!=p->val){
                ret = false;
                break;
            }else{
                S.pop();
                p=p->next;
            }
        }
        return ret;
    }
};