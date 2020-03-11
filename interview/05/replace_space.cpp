#include<string>

using namespace std;


class Solution {
public:
    string replaceSpace(string s) {
        stringstream ss;
        for (char ch : s)
        {
            if (ch == ' '){
                ss << "%20";
            }else{
                ss << ch;
            }
        }
        return ss.str();
    }
};