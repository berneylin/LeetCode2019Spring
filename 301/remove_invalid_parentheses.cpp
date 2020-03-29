#include<vector>
#include<string>
#include<queue>
#include<set>
using namespace std;


class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        bool findFlag = false;
        vector<string> ansVec;
        set<string> ansSet;
        set<string> bfsQ;

        bfsQ.insert(s);

        while(!bfsQ.empty()){
            set<string> nextLevelSet;
            while(!bfsQ.empty()){
                string tmpStr = *bfsQ.begin();
                bfsQ.erase(bfsQ.begin());

                int cnt = 0;
                for(char ch: tmpStr){
                    if(ch=='(') cnt++;
                    if(ch==')') cnt--;
                    if(cnt<0) break;
                }

                if (cnt==0) {
                    findFlag = true;
                    ansVec.push_back(tmpStr);
                }

                if(!findFlag){
                    for(int i=0; i<tmpStr.size(); i++){
                        if((tmpStr[i]=='(' && cnt > 0) || (tmpStr[i]==')' && cnt < 0)){
                            // 左括号多了 删左括号
                            string nextLevelStr = tmpStr;
                            nextLevelStr.erase(nextLevelStr.begin()+i);
                            nextLevelSet.insert(nextLevelStr);
                        }
                    }
                }
            }
            bfsQ = nextLevelSet;
        }
        
        return ansVec;
    }
};