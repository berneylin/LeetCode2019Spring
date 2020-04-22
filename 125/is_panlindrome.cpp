#include<string>
using namespace std;


class Solution {
public:
    inline char lowerCase(char ch){
        if(ch>='a' && ch <='z') return ch;
        else if(ch>='A' && ch<='Z') return 'a'+ch-'A';
        else return ch;
    }
    inline bool isLetter(char ch){
        return (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9');
    }
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l<r){
            while(l<r && !isLetter(s[l])) l++;
            while(l<r && !isLetter(s[r])) r--;
            if(lowerCase(s[l])!=lowerCase(s[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};