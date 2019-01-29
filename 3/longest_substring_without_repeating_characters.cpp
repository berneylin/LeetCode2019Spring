#include<cstring>
#include<set>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> S;
        int sLen = s.size();
        int maxLen = 0;
        int thisLen = 0;
        char ch;
        for(int i=0;i<sLen;i++){
            if(S.find(s[i])==S.end()){
                S.insert(s[i]);
                thisLen++;
                if(i==sLen-1){
                    maxLen = thisLen>maxLen?thisLen:maxLen;
                }
            }else{
                maxLen = thisLen>maxLen?thisLen:maxLen;
                ch = s[i];
                thisLen = 0;
                i--;
                while(i>=0&&s[i]!=ch) i--;
                S.clear();
            }
        }
        return maxLen;
    }
};
