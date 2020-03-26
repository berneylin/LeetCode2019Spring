#include<map>
using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        int sLen = s.length();
        if (sLen==0) return ' ';
        map<char, int> chCntMap;
        for (int i = 0; i < sLen; i++) {
            if (chCntMap.find(s[i]) == chCntMap.end()) {
                chCntMap[s[i]] = 0;
            }
            chCntMap[s[i]] ++;
        }
        char ans = ' ';

        for (int i=0; i<sLen; i++) {
            if(chCntMap[s[i]] == 1) {
                ans = s[i];
                break;
            }
        }
        return ans;
    }
};