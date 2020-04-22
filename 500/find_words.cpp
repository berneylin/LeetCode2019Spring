#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int mode[26] = {
            1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2, 2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2
        };
        vector<string> ansVec;
        for(const auto &thisWord: words){
            bool legalFlag = true;
            if(thisWord.length()>1) {
                for(int idx=1; legalFlag && idx<thisWord.length(); idx++){
                    int idxPre = thisWord[idx-1]>='a'?thisWord[idx-1]-'a':thisWord[idx-1]-'A';
                    int idxThis = thisWord[idx]>='a'?thisWord[idx]-'a':thisWord[idx]-'A';
                    legalFlag = (mode[idxPre]==mode[idxThis]);
                }
            }   
            if(legalFlag)
                ansVec.push_back(thisWord);
        }

        return ansVec;
    }
};