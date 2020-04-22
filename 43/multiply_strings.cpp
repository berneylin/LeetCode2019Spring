#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.empty()) return num2;
        if(num2.empty()) return num1;
        if(num1=="0"||num2=="0") return "0";
        vector<string> tmpVec;
        for(int idx2=num2.length()-1; idx2>=0; idx2--){
            char &digit = num2[idx2];
            string thisAns;
            int zeroCnt = (num2.length()-1-idx2);
            while(zeroCnt--) thisAns.push_back('0');
            int carry = 0;
            for(int idx1=num1.length()-1; idx1>=0; idx1--){
                int thisMul = (digit-'0')*(num1[idx1]-'0')+carry;
                carry = thisMul / 10;
                thisMul %= 10;
                thisAns.push_back(thisMul+'0');
            }
            if(carry!=0) thisAns.push_back(carry+'0');
            tmpVec.push_back(thisAns);
        }
        string ans;
        for(int i=0; i<tmpVec.size(); i++){
            if(i==0) ans = tmpVec[i];
            else {
                // 加到ans上
                int carry = 0, thisSum;
                string newAns;
                int addIdx1 = 0, addIdx2 = 0;
                while(addIdx1<ans.length() && addIdx2<tmpVec[i].length()){
                    thisSum = (ans[addIdx1]-'0') + (tmpVec[i][addIdx2]-'0') + carry;
                    carry = thisSum / 10;
                    thisSum %= 10;
                    newAns.push_back(thisSum+'0');
                    addIdx1++;
                    addIdx2++;
                }
                while(addIdx1<ans.length()){
                    thisSum = (ans[addIdx1]-'0') + carry;
                    carry = thisSum/10;
                    thisSum %= 10;
                    newAns.push_back(thisSum+'0');
                    addIdx1++;
                }
                while(addIdx2<tmpVec[i].length()){
                    thisSum = (tmpVec[i][addIdx2]-'0') + carry;
                    carry = thisSum / 10;
                    thisSum %= 10;
                    newAns.push_back(thisSum+'0');
                    addIdx2++;
                }
                if(carry!=0) newAns.push_back(carry+'0');
                ans = newAns;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(void){
    string num1, num2;
    Solution *sol = new Solution();
    while(cin >> num1){
        cin >> num2;
        cout << sol->multiply(num1, num2) << endl;
    }
    return 0;
}