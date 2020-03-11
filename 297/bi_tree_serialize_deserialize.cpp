#include <string>

using namespace std;

struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        dfs(root, ss);
        return ss.str();
    }

    void dfs(TreeNode* node, stringstream& ss) {
        if (!node) {
            ss << "N ";
            return;
        }
        ss << to_string(node->val) << " ";
        dfs(node->left, ss);
        dfs(node->right, ss);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        TreeNode* rtnRoot = nullptr;
        stringstream ss(data);
        rebuild(rtnRoot, ss);
        return rtnRoot;
    }

    void rebuild(TreeNode* &node, stringstream& ss){
        string tmpStr;
        ss >> tmpStr;
        if (tmpStr[0] == 'N'){
            node = nullptr;
            return;
        }else{
            int v = stoi(tmpStr);
            node = new TreeNode(v);
            rebuild(node->left, ss);
            rebuild(node->right, ss);
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));