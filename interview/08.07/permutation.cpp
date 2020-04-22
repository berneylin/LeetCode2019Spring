#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> permutation(string S) {
        if(S.empty()) return {};
        vector<string> ans;
        int slength = S.length();
        string tmpStr = S;
        do{
            ans.push_back(tmpStr);

            // get next permutation
            int j = slength-1;
            while(j>0 && tmpStr[j-1]>=tmpStr[j]) j--;
            if(j==0){
                int l = 0, r = slength-1;
                while(l<r){
                    char tmpChar = tmpStr[l];
                    tmpStr[l] = tmpStr[r];
                    tmpStr[r] = tmpChar;
                    l++;
                    r--;
                }
            }
            else{
                int i = j-1;
                // 1. 从j开始，找到最小的比i大的
                int k = j;
                while(k<slength && tmpStr[k]>=tmpStr[i]) k++;
                k--;

                // 2. 交换i和k
                char tmpChar = tmpStr[k];
                tmpStr[k] = tmpStr[i];
                tmpStr[i] = tmpChar;

                // 3. 从j开始到结束 逆置
                int l = j, r = slength-1;
                while(l<r){
                    tmpChar = tmpStr[l];
                    tmpStr[l] = tmpStr[r];
                    tmpStr[r] = tmpChar;
                    l++;
                    r--;
                }
            }
        }while(tmpStr!=S);
        return ans;
    }
};