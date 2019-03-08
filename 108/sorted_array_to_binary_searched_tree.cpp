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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        return constructBST(nums, 0, nums.size()-1);
    }
    
    TreeNode* constructBST(vector<int>& nums, int l, int r) {
        if(l>r) return nullptr;
        int m = l + (r-l)/2;
        TreeNode* ret = new TreeNode(nums[m]);
        ret->left = constructBST(nums, l, m-1);
        ret->right = constructBST(nums, m+1, r);
        return ret;
    }
};