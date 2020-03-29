#include<string>
#include<vector>
using namespace std;


class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ansVec, tmpStrVec;
        if(s.empty()) return ansVec;
        vector<bool> mem(s.length()+1, true);
        dfs(s, ansVec, 0, tmpStrVec, wordDict, mem);

        return ansVec;
    }

    bool dfs(string &s, vector<string> &ansVector, int startIdx, vector<string> &tmpStrVec, vector<string> &wordDict, vector<bool> &mem) {
        if(mem[startIdx] == false){
            return false;
        }

        if(startIdx==s.length()){
            string ans = "";
            for(int i=0; i<tmpStrVec.size(); i++){
                ans += tmpStrVec[i];
                if(i!=tmpStrVec.size()-1) {
                    ans += " ";
                }
            }
            ansVector.push_back(ans);
            return true;
        }
        bool nextFlag = false;
        for(string word: wordDict){
            int curWordLength = word.length();
            if(startIdx+curWordLength<=s.length()){
                if(s.substr(startIdx, curWordLength)==word){
                    tmpStrVec.push_back(word);
                    nextFlag |= dfs(s, ansVector, startIdx+curWordLength, tmpStrVec, wordDict, mem);
                    tmpStrVec.pop_back();
                }
            }
        }
        mem[startIdx] = nextFlag;
        return nextFlag;
    }
};