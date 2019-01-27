#include<string>
#include<iostream>
using namespace std;

// class Solution {
// public:
    string longestPalindrome(string s) {
        string ret = "";
        int sLength = s.size();
        if(sLength==0) return ret;
        /* 2n-1 axies of symmetry overall */

        for(int i=0;i<(2*sLength - 1);i++){
            string tmp = "";
            //traverse all conditions
            if(i&1){
                // odd condition, use interval as axis
                int l = (i-1)/2, r = (i+1)/2; // two pointers method
                while(l>=0&&r<sLength){
                    if(s[l]==s[r]){
                        tmp = s[l] + tmp + s[r]; // concatenate
                    }else{
                        break;
                    }
                    l--;r++;
                }
            }else{
                //even condition, use character as axis
                int charIdx = i/2;
                tmp = s[charIdx];
                int delta = 1;
                while((charIdx-delta)>=0&&(charIdx+delta)<sLength){ // while legal position
                    if(s[charIdx-delta]==s[charIdx+delta]){ // if symmetry
                        tmp = s[charIdx-delta] + tmp + s[charIdx+delta];  // concatenate the substring
                    }else{
                        break;
                    }
                    delta++;
                }
            }
            if(tmp.size()>ret.size()){  // replace the return string with longer one
                ret = tmp;
            }
        }
        return ret;
    }
// };

int main(void){
    string s;
    cin >> s;
    cout << "longest: " << longestPalindrome(s);
    return 0;
}