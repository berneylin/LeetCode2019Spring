#include<string>
#include<vector>
using namespace std;



class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size();
        if(len1==0&&len2==0) return "0";
        if(len1==0) return num2;
        if(len2==0) return num1;
        if(len1<len2){
            string tmp = num1;
            num1 = num2;
            num2 = tmp;
            len1 = num1.size();
            len2 = num2.size();
        }

        vector<int> ansVec;
        int idx1 = len1 - 1, idx2 = len2 - 1;

        int res = 0;
        while(idx2>=0){
            int thisSum = (num1[idx1]-'0') + (num2[idx2]-'0') + res;
            res = thisSum / 10;
            thisSum %= 10;
            ansVec.push_back(thisSum);
            idx1--;
            idx2--;
        }

        while(idx1>=0){
            int thisSum = (num1[idx1]-'0') + res;
            res = thisSum / 10;
            thisSum %= 10;
            ansVec.push_back(thisSum);
            idx1--;
        }

        if(res) ansVec.push_back(res);
        string ansStr = "";
        for(int i=ansVec.size()-1;i>=0;i--){
            ansStr.push_back(char('0'+ansVec[i]));
        }

        return ansStr;
    }
};