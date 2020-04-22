#include<string>
using namespace std;

class Solution {
public:
    int strToInt(string str) {
        if(str.empty()) return 0;
        long ans = 0;
        bool negFlag = true;
        int idx = 0;
        while(idx<str.length() && str[idx]==' ') idx++;
        if(idx==str.length()) return 0;
        if(str[idx]!='+' && str[idx]!='-' && (str[idx] > '9' || str[idx] < '0')) return 0;
        if(str[idx] == '+' || (str[idx] <= '9' && str[idx] >= '0')) negFlag = false;
        if(str[idx] == '+' || str[idx] == '-') idx++;
        if(idx==str.length() || (str[idx] > '9' || str[idx] < '0')) return 0;
        while(idx<str.length() && str[idx] >= '0' && str[idx] <= '9'){
            ans *= 10;
            ans += str[idx]-'0';
            if(negFlag && -ans < ((int)0x80000000)){
                return 0x80000000;
            }
            else if(!negFlag && ans > ((int)0x7FFFFFFF)){
                return 0x7FFFFFFF;
            }
            idx++;
        }
        return negFlag?-ans:ans;
    }
};