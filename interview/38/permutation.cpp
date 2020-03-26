#include<vector>
#include<string>
#include<set>

using namespace std;




class Solution {
public:
    vector<string> permutation(string s) {
        set<string> ansSet;
        vector<string> ansVec;
        string tmpStr = "";
        vector<bool> visited(s.length(), false);
        dfs(s, ansSet, visited, tmpStr);
        for (string eachStr : ansSet) {
            ansVec.push_back(eachStr);
        }
        
        return ansVec;
    }

    void dfs(string &s, set<string> &ansSet, vector<bool> &visited, string &tmpStr){
        if (tmpStr.length()==s.length()) {
            ansSet.insert(tmpStr);
            return;
        }
        for (int i = 0; i < s.length(); ++i) {
            if (visited[i] == false) {
                tmpStr.push_back(s[i]);
                visited[i] = true;
                dfs(s, ansSet, visited, tmpStr);
                visited[i] = false;
                tmpStr.pop_back();
            }
        }
    }
};