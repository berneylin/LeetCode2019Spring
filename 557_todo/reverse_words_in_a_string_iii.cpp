#include<cstring>
/* c version */
char* reverseWords(char* s) {
    int sLen = strlen(s);
    int halfSLen = sLen / 2;
    char tmp;
    for(int i=0;i<halfSLen;i++){
        /* reverse the entire string */
        tmp = s[i];
        s[i] = s[sLen-1-i];
        s[sLen-1-i] = s[i];
    }

    



}