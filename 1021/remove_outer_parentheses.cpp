#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        if(S.empty()) return S;
        string ans;
        stack<char> tmpS;
        for(const char &ch: S){
            if(ch=='('){
                tmpS.push('(');
                if(tmpS.size()>1) ans.push_back('(');
            }else{
                if(tmpS.size()>1) ans.push_back(')');
                tmpS.pop();
            }
        }
        return ans;
    }
};

// 输入："(()())(())"
// 输出："()()()"