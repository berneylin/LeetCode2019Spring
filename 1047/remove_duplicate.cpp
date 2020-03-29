#include<stack>
#include<string>
using namespace std;


class Solution {
public:
    string removeDuplicates(string S) {
        if(S.empty()) return S;
        stack<char> s1, s2;

        for(char c: S) s1.push(c);

        while(!s1.empty()){
            if(!s2.empty() && s1.top()==s2.top()){
                s2.pop();
            }else{
                s2.push(s1.top());
            }
            s1.pop();
        }

        string ans = "";
        while(!s2.empty()){
            ans.push_back(s2.top());
            s2.pop();
        }
        return ans;
    }
};