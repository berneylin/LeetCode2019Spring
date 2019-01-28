#include<cstring>
#include<cstdio>
/* c version */

void reverse(char* str, int start, int end){
    /* reverse the substring of str indexed [start, end) */
    int halfLen = (end - start) >> 1;
    char tmp;
    for(int i=0;i<halfLen;i++){
        /* swap */
        tmp = str[start+i];
        str[start + i] = str[end-i-1];
        str[end-i-1] = tmp;
    }
}


char* reverseWords(char* str) {
    int sLen = strlen(str);
    int i = 0;

    while(i<sLen){
        if(str[i]==' '){
            i++;
        }else{
            int s = i;
            while(i<sLen && str[i]!=' ') i++;
            reverse(str, s, i);
        }
    }
    return str;
}