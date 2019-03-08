/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<set>
using namespace std;

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        set<int> S;
        bool ans = false;
        traverse(ans, S, k, root);
        return ans;
    }

    void traverse(bool &ans, set<int> &S, const int &k, TreeNode* T) {
        if(!T||ans) return;
        traverse(ans, S, k, T->left);

        int thisNum = T->val;
        if(S.find(k-thisNum)!=S.end()) {
            ans = true;
            return;
        }else{
            S.insert(thisNum);
        }
        traverse(ans, S, k, T->right);
    }
};