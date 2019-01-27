#include<map>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        bool ret = true;
        map<char, char> M;
        stack<char> S;
        M.insert(make_pair(')', '('));
        M.insert(make_pair(']', '['));
        M.insert(make_pair('}', '{'));
        for(string::iterator it=s.begin();it!=s.end();it++){
            if((*it)=='['||(*it)=='('||(*it)=='{'){
                S.push(*it);
            }else{
                if(S.empty()){
                    ret = false;
                    break;
                }else{
                    if(S.top()!=M[*it]){
                        ret = false;
                        break;
                    }else{
                        S.pop();
                    }
                }
                
            }
        }

        if(ret&&!S.empty()){
            ret = false;
        }

        return ret;
    }
};