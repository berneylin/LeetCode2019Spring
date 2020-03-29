#include<string>
using namespace std;

class Solution {
public:
    string compressString(string S) {
        if(S.length() <= 2) return S;
        int i = 0, j = 1;
        string ans = "";
        while(i<S.length()){
            if(S[i]==S[j]){
                j++;
            }else{
                ans += S[i];
                ans += to_string(j-i);
                i=j;
                j++;
            }
            // 边界处理
            if(j==S.length()){
                ans += S[i];
                ans += to_string(j-i);
                break;
            }
        }
        return ans.length()<S.length()?ans:S;
    }
};