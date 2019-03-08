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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        vector<long> levelSum;
        vector<int> levelCnt;
        if(!root) return ans;
        traverse(levelSum, levelCnt, 0, root);
        int levels = levelSum.size();
        for(int i=0;i<levels;i++){
            ans.push_back((double)levelSum[i]/(double)levelCnt[i]);
        }
        return ans;
    }

    void traverse(vector<long> &levelSum, vector<int> &levelCnt, int level, TreeNode* T){
        if(!T) return;
        if(level>=levelSum.size()) {  // 当前遍历到的节点为该层第一个遍历到的实节点
            levelSum.push_back(T->val);
            levelCnt.push_back(1);
        }else{
            levelSum[level] += T->val;
            levelCnt[level] ++;
        }
        traverse(levelSum, levelCnt, level+1, T->left);
        traverse(levelSum, levelCnt, level+1, T->right);
    }

};