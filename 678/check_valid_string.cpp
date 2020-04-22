#include<string>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int leftCnt = 0, starCnt = 0;
        for(const char &ch: s){
            if(ch=='(') leftCnt++;
            else if(ch=='*') starCnt++;
            else if(ch==')'){
                if(leftCnt==0){
                    if(starCnt==0) return false;
                    else starCnt--;
                }
                else leftCnt--;
            }
        }
        int rightCnt = 0;
        starCnt = 0;
        for(int i=s.length()-1; i>=0; i--){
            if(s[i]==')') rightCnt++;
            else if(s[i]=='*') starCnt++;
            else if(s[i]=='('){
                if(rightCnt==0){
                    if(starCnt==0) return false;
                    else starCnt--;
                }
                else rightCnt--;
            }
        }
        return true;
    }
};