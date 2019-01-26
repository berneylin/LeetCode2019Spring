#include<string>

class Solution {
public:
    string longestCommonPrefix(const vector<string>& strs) {
        string ret = "";
        if(!strs.size()) return ret;
        int count = 0;
        while(1){
            string currRet = ret;
            count ++;
            bool exitFlag = false;
            for(string str: strs){
                if(currRet.size()<count) { // initilization
                    currRet+=str[count-1];
                }

                if(count>str.size()){ // `count' exceeds the length of the shortest string in `strs' vector
                    exitFlag = true;
                    break;
                }
                else{ // always append the unlike character to the tail of currRet
                    if(str[count-1]!=currRet[currRet.size()-1]){
                        currRet += str[count-1];
                    }
                }
            }
            if(count!=currRet.size()) exitFlag = true;
            if(exitFlag) break;
            ret = currRet;
        }
        return ret;
    }
};