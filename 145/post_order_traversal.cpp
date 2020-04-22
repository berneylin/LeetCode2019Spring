#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> ansVec;
        TreeNode *ptr = root;
        TreeNode *pre = NULL;
        stack<TreeNode*> tmpS;
        while(ptr != NULL || !tmpS.empty()){
            if(ptr != NULL){
                tmpS.push(ptr);
                ptr = ptr->left;
            }
            else{
                ptr = tmpS.top();
                if(ptr->right==NULL || ptr->right==pre){
                    ansVec.push_back(ptr->val);
                    pre = ptr;
                    ptr = NULL;
                    tmpS.pop();
                }
                else{
                    ptr = ptr->right;
                }
            }
        }
        return ansVec;
    }
};