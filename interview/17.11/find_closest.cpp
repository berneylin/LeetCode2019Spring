#include<vector>
#include<string>
#include<algorithm>
using namespace std;


class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int idx1 = -1, idx2 = -1, ans = 0x7FFFFFF;
        if(word1==word2 || words.empty()) return 0;
        for(int i=0; i<words.size(); i++){
            string &thisWord = words[i];
            if(thisWord!=word1 && thisWord!=word2) continue;
            if(thisWord==word1){
                if(idx2!=-1) ans = min(ans, i-idx2);
                idx1 = i;
            }else{
                if(idx1!=-1) ans = min(ans, i-idx1);
                idx2 = i;
            }
            if(ans==1) break;
        }
        return ans;
    }
};