#include<string>
using namespace std;

string mode[10] = {
    "", //0
    "", //1
    "abc", //2
    "def", //3
    "ghi", //4
    "jkl", //5
    "mno", //6
    "pqrs", //7
    "tuv", //8
    "wxyz" //9
};



class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        int digitsLen = digits.size();
        for(int i=0;i<digitsLen;i++){
            int currDigitIndex = digits[i] - '0';
            string modeStr = mode[currDigitIndex];
            if(ret.empty()){
                // initialize
                int modeSize = modeStr.size();
                for(int j=0;j<modeSize;j++){
                    string tmp = "";
                    tmp += modeStr[j];
                    ret.push_back(tmp);
                }
            }else{
                cartesianProduct(ret, modeStr);
            }
        }
        return ret;
    }

    void cartesianProduct(vector<string> &pre, string modeStr){
        // traverse previous vector to made new vector
        vector<string> newVec;
        int preSize = pre.size();
        int modeSize = modeStr.size();
        for(int i=0;i<preSize;i++){
            for(int j=0;j<modeSize;j++){
                string tmp = pre[i] + modeStr[j];
                newVec.push_back(tmp);
            }
        }

        // update previous vector
        pre = newVec;
    }
};