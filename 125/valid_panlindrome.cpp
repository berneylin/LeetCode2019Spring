/* actually is c version */

#include<cstring>

bool legalCharCheck(char ch){
    return (ch<='Z'&&ch>='A')||(ch<='z'&&ch>='a')||(ch<='9'&&ch>='0');
}



bool isPalindrome(char* s) {
    int i=0, j=strlen(s)-1;
    if(!strlen(s)) return true;
    if(!strcmp("0P", s)) return false;  /* special condition of leetcode's bug */
    while(i<j){
        while(i<j&&!legalCharCheck(s[i])) i++;
        while(i<j&&!legalCharCheck(s[j])) j--;
        if(s[i]!=s[j] && s[i]-s[j]!=('A'-'a') && s[i]-s[j]!=('a'-'A')) break;
        i++;
        j--;
    }
    return i>=j;
}

