#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> M;
        int sSize = s.size();
        bool ansFlag = true;
        vector<char> usedV;
        for(int i=0;i<sSize && ansFlag;i++) {
            if(M.find(s[i])==M.end()){
                if(find(usedV.begin(), usedV.end(), t[i])!=usedV.end()) ansFlag = false;
                else {
                    M.insert(pair<char, char>(s[i], t[i]));
                    usedV.push_back(t[i]);
                }
            }else{
                ansFlag = M[s[i]]==t[i];
            }
        }
        return ansFlag;
    }
};