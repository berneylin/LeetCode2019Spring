#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ansVec;
        vector<string> tmpVec;
        if(s.empty()) return ansVec;
        dfs(s, 0, ansVec, tmpVec);
        return ansVec;
    }

    void dfs(string &s, int startIdx, vector<vector<string> > &ansVec, vector<string> &tmpVec){
        if(startIdx==s.length()){
            ansVec.push_back(tmpVec);
            return;
        };

        for(int i=startIdx; i<s.size(); i++){
            if(checkLegal(s, startIdx, i)){
                tmpVec.push_back(s.substr(startIdx, i-startIdx+1));
                dfs(s, i+1, ansVec, tmpVec);
                tmpVec.pop_back();
            }
        }
    }
private:
    bool checkLegal(string& s, int i, int j){
        // 判断s[i:j+1]是否为回文串
        int l = i, r = j;
        while(l<r){
            if(s[l]!=s[r]) break;
            else {
                l++;
                r--;
            }
        }
        return l>=r;
    }


};