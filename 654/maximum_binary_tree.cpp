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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0) return nullptr;
        TreeNode* root = buildMaximumBinaryTree(nums, 0, nums.size()-1);
        return root;
    }

    TreeNode* buildMaximumBinaryTree(vector<int>& nums, int l, int r) {
        if(l>r) return nullptr;
        int maxIdx = l;
        int maxNum = nums[l];
        for(int i=l;i<=r;i++){
            if(maxNum<nums[i]){
                maxIdx = i;
                maxNum = nums[i];
            }
        }
        TreeNode* ret = new TreeNode(maxNum);
        ret->left = buildMaximumBinaryTree(nums, l, maxIdx-1);
        ret->right = buildMaximumBinaryTree(nums, maxIdx+1, r);
        return ret;
    }
};