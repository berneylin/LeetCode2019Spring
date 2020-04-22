#include<string>
#include<map>
#include<algorithm>
using namespace std;


class Solution {
public:
    string frequencySort(string s) {
        map<char, int> cntMap;
        if(s.empty()) return s;
        for(const auto &ch: s){
            if(cntMap.find(ch)==cntMap.end()) cntMap[ch] = 0;
            cntMap[ch]++;
        }
        string ans(s.size());
        while(!cntMap.empty()){
            int thisMax = 0;
            char thisMaxChar = 0;
            for(const auto &p: cntMap){
                if(p.second>thisMax){
                    thisMax = p.second;
                    thisMaxChar = p.first;
                }
            }
            while(thisMax--) ans.push_back(thisMaxChar);
            cntMap.erase(thisMaxChar);
        }

        return ans;
    }
};