#include<list>
using namespace std;

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if(!root) return ans;
        list<TreeNode* > L;
        L.push_back(root);
        bool leftFirstFlag = true;
        while(!L.empty()){
            list<TreeNode* > newL;
            vector<int> tmp;
            if(leftFirstFlag){
                for(list<TreeNode* >::iterator it=L.begin();it!=L.end();it++){  // 正向遍历（从左到右）
                    tmp.push_back((*it)->val);
                    if((*it)->left) newL.push_back((*it)->left);
                    if((*it)->right) newL.push_back((*it)->right);
                }
            }else{
                for(list<TreeNode* >::reverse_iterator it=L.rbegin();it!=L.rend();it++){  // 反向遍历（从右到左）
                    tmp.push_back((*it)->val);
                    if((*it)->right) newL.insert(newL.begin(), (*it)->right);
                    if((*it)->left) newL.insert(newL.begin(), (*it)->left); 
                }
            }
            ans.push_back(tmp);
            L = newL;
            leftFirstFlag = !leftFirstFlag;
        }
        return ans;
    }
};