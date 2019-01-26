#include<vector>
#include<string>
using namespace std;

class Solution {
private:
    string int2str(int x){
        string ret = "";
        while(x){
            ret = (char)(x%10+'0') + ret;
            x /= 10;
        }
        return ret;
    }
    string calcCAS(string preS){
        string ret = "";
        int len = preS.size();
        char currChar = preS[0];
        int i = 0;
        while(i<len){
            int count = 1;
            int j = i+1;
            while(j<len&&preS[j]==currChar){ // legal position and repeated num of current char
                count++;
                j++;
            }
            string strCount = int2str(count);
            ret += strCount + currChar;
            if (j<len){
                i = j;
                currChar = preS[j];
            }else break;
        }

        return ret;
    }
public:
    string countAndSay(int n) {
        vector<string> vStr;
        vStr.push_back("1");
        for(int i=1;i<n;i++){
            vStr.push_back(calcCAS(vStr[i-1]));
        }
        return vStr[n-1];
    }
};