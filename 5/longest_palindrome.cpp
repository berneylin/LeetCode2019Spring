#include<string>
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int sLen = s.length();
        if(sLen==0) return ans;
        int arrSize = 2*sLen-1;
        int maxLen = 0, maxIdx = 0;
        for(int i=0; i<arrSize; i++){
            int thisLen = 0;
            if(i&1){
                // 奇数
                int l = i/2, r = (i/2)+1;
                while(l>=0 && r<sLen && s[l]==s[r]){
                    l--;
                    r++;
                }
                thisLen = r-l-1;
            }
            else{
                // 偶数
                int l = i/2, r = i/2;
                while(l>=0 && r<sLen && s[l]==s[r]){
                    l--;
                    r++;
                }
                thisLen = r-l-1;
            }
            if(thisLen>maxLen){
                maxIdx = i;
                maxLen = thisLen;
            }
        }
        string ans;
        int l, r;
        if(maxIdx & 1){
            l = maxIdx/2;
            r = (maxIdx/2)+1;
        }
        else{
            l = maxIdx/2;
            r = maxIdx/2;
        }
        if(l==r) {
            ans.push_back(s[l]);
            l--;
            r++;
        }
        while(ans.length()!=maxLen){
            ans = s[l] + ans + s[r];
            l--;
            r++;
        }
        return ans;
    }
};