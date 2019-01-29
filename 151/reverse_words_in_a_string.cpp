#include<cstring>
#include<cstdio>

void reverseString(char* str, int s, int e){
    /* reverse the string from [s, e-1] */
    int halfLen = (e-s)>>1;
    char tmp;
    for(int i=0;i<halfLen;i++){
        tmp = str[s+i];
        str[s+i] = str[e-i-1];
        str[e-i-1] = tmp;
    }
}

void moveString(char* str, int newS, int oldS, int len){
    /* newS must be smaller than olds */
    for(int i=0;i<len;i++){
        str[newS+i] = str[oldS+i];
    }
}

void reverseWords(char *str) {
    int sLen = strlen(str) - 1;
    while(sLen>=0&&str[sLen]==' ') sLen--;
    str[sLen+1] = '\0';  // remove the original tail space
    sLen = strlen(str);  // update str's length
    int i = 0;
    while(i<sLen && str[i]==' ') i++;
    if(i) moveString(str, 0, i, sLen-i+1);  // plus one for the end char `\0'
    sLen = strlen(str); // now the string has been striped
    reverseString(str, 0, sLen);  // firstly, reverse the entire string
    int j = 0;
    i = 0;
    while(j<sLen){
        while(j<sLen && str[j]!=' ') j++;
        reverseString(str, i, j);  // reverse the word
        int thisWordLen = j-i;
        int oldI = i;
        while(i>1 && str[i-1]==' ' && str[i-2]==' ') i--;
        if(i!=oldI){
            moveString(str, i, oldI, sLen-oldI+1);
        }
        sLen = strlen(str);
        j = i + thisWordLen;
        while(j<sLen&&str[j]==' ') j++;
        i = j;
    }
}


int main(void){
    char tmp[100];
    gets(tmp);
    reverseWords(tmp);
    printf("%s", tmp);

    return 0;
}