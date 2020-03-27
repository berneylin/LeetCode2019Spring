#include<string>
#include<vector>
using namespace std;


class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if(p.empty()) return 0;
        vector<int> maxLenTail(26, 0);
        int curLen = 0;
        for (int i=0; i<p.size(); i++) {
            if(i>=1 && (p[i]-p[i-1]+26)%26==1) curLen++;
            else curLen = 1;
            maxLenTail[p[i]-'a'] = maxLenTail[p[i]-'a']>curLen?maxLenTail[p[i]-'a']:curLen;
        }
        int ans = 0;
        for (int i=0; i<26; i++){
            ans += maxLenTail[i];
        }
        return ans;
    }
};