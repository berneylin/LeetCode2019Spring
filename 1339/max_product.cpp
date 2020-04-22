#include<algorithm>
#include<unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxProduct(TreeNode* root) {
        sumMap.clear();
        long long ans = -1;
        long long totalSum = calc(root);
        for(const auto &eachPair: sumMap){
            ans = max(ans, (totalSum-eachPair.second)*eachPair.second);
        }
        return (int)(ans%_MODE);
    }

    long long calc(TreeNode* node){
        if(!node) return 0;
        long long left = calc(node->left);
        long long right = calc(node->right);
        sumMap[node] = node->val + left + right;
        return sumMap[node];
    }

private:
    const long long _MODE = 1e9 + 7;
    unordered_map<TreeNode*, long long> sumMap;
};