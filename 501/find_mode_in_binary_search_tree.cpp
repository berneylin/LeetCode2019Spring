/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int currentTimes = 0;
    int maxTimes = 0;
    int previousNum;

    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        inOrderFindMaxTimes(root);
        maxTimes = maxTimes>currentTimes?maxTimes:currentTimes;  // 尾更新
        currentTimes = 0;  // 重新统计
        inOrderFindMode(root, ans);
        if(currentTimes==maxTimes) ans.push_back(previousNum);  // 尾更新
        return ans;
    }

    void inOrderFindMaxTimes(TreeNode* T) {
        if(!T) return;
        inOrderFindMaxTimes(T->left);
        // 中序遍历BST 可视为升序遍历有序表
        if(currentTimes==0){
            // 初始化
            currentTimes = 1;
            previousNum = T->val;
        }else{
            if(T->val==previousNum) currentTimes++;
            else {
                maxTimes = maxTimes>currentTimes?maxTimes:currentTimes;
                previousNum = T->val;
                currentTimes = 1;
            }
        }
        inOrderFindMaxTimes(T->right);
    }

    void inOrderFindMode(TreeNode* T, vector<int> &ans) {
        if(!T) return;
        inOrderFindMode(T->left, ans);
        if(currentTimes==0) {
            currentTimes = 1;
            previousNum = T->val;
        }else{
            if(T->val==previousNum) currentTimes++;
            else{
                if(currentTimes==maxTimes) ans.push_back(previousNum);
                previousNum = T->val;
                currentTimes = 1;
            }
        }
        inOrderFindMode(T->right, ans);
    }
};