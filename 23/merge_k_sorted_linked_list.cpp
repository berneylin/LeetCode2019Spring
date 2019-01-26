#include<climits>

/**
 *  Time Complexity: O(mn)
 *  Space Complexity: O(mn)
 *  m: the size of original vector
 *  n: the (mean) length of the linked list
 * /


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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ret = nullptr; // initialize the return pointer
        ListNode* tail = nullptr;// for insert use
        int listSize = lists.size();
        if(listSize==0) return ret; // boundary condition
        ListNode* tmpPtr[listSize];  // tmp pointer array to traverse each linked list

        for(int i=0;i<listSize;i++){
            tmpPtr[i] = lists[i];
        } // initialize the temporary traverse pointer array


        
        while(true){
            int thisMinVal = INT_MAX;
            int thisMinIdx = -1;

            for(int i=0;i<listSize;i++){ // start traversing
                if(tmpPtr[i]){ // if not null
                    if(thisMinVal>tmpPtr[i]->val){
                        // update
                        thisMinIdx = i;
                        thisMinVal = tmpPtr[i]->val;
                    }
                }
            }
            if(thisMinIdx==-1) break; // cannot find any real number to insert

            // create and insert
            ListNode* tmp = new ListNode(thisMinVal);
            if (ret==nullptr) ret = tail = tmp; // first time condition
            else {
                tail->next = tmp;
                tail = tail->next;
            }

            // finish process
            tmpPtr[thisMinIdx] = tmpPtr[thisMinIdx]->next;
        }

        return ret;
        
    }
};