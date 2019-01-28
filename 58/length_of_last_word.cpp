class Solution {
public:
    int lengthOfLastWord(string s) {
        int ret = 0;
        int sLen = s.size() - 1;
        while(sLen>=0 && s[sLen]==' ') sLen--;  // find the last character of the last word
        int i = sLen;
        while(i>=0){
            if(s[i]==' ') break;
            else i--;
        }
        ret = sLen - i;
        return ret;
    }
};

