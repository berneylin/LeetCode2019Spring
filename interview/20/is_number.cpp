#include<string>
using namespace std;


class Solution {
public:
    bool isNumber(string s) {
        int idx = 0;
        while(idx<s.size() && s[idx] == ' ') idx++;
        if (idx == s.size()) return false;
        s = s.substr(idx);

        idx = s.size() - 1;
        while(idx>=0 && s[idx] == ' ') idx--;
        s = s.substr(0, idx+1);

        int ePos = s.find('e');
        if (ePos == -1)
            return checkBaseNum(s);
        else
            return checkBaseNum(s.substr(0, ePos)) && checkExponent(s.substr(ePos+1));
    }

    bool checkExponent(string s) {
        if (s.empty()) return false; 
        bool rtnFlag = false;
        for (int i=0; i<s.size(); i++) {
            if (s[i]=='+' || s[i]=='-'){
                 if (i != 0) return false;
            }
            else if (s[i] < '0' || s[i] > '9'){
                return false;
            }
            else{
                rtnFlag = true;
            }
        }
        return rtnFlag;
    }

    bool checkBaseNum(string s) {
        if (s.empty()) return false;
        bool rtnFlag = false, pointExist = false;
        for (int i=0; i < s.size(); i++) {
            if (s[i]=='+' || s[i]=='-'){
                if (i!=0) return false;
            } 
            else if (s[i] == '.') {
                if(pointExist) return false;
                pointExist = true;
            }else if (s[i] < '0' || s[i] > '9'){
                return false;
            }
            else{
                rtnFlag = true;
            }
        }

        return rtnFlag;
    }
};