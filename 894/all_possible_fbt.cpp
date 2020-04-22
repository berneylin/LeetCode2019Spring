#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N%2==0) return {};
        if(N==1) return {new TreeNode(0)};
        vector<TreeNode*> rtnVec;
        for(int i=1; i<N; i++){
            vector<TreeNode*> leftVec = allPossibleFBT(i);
            vector<TreeNode*> rightVec = allPossibleFBT(N-i-1);
            for(TreeNode* &left: leftVec){
                for(TreeNode* &right: rightVec){
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    rtnVec.push_back(root);
                }
            }
        }
        return rtnVec;        
    }
};