#include<string>
using namespace std;


class Solution {
public:
    inline int isVowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')?1:0;
    }
    int maxVowels(string s, int k) {
        int ans = 0;
        int sLen = s.length();
        int lhs = 0, rhs = 0;
        int curCnt = 0;
        while(rhs < sLen){
            char &curChar = s[rhs];
            curCnt += isVowel(curChar);
            if(rhs-lhs+1 <= k){
                rhs++;
            }else{
                curCnt -= isVowel(s[lhs]);
                lhs ++;
                rhs ++;
            }
            if(ans<curCnt) ans = curCnt;
        }
        return ans;
    }
};