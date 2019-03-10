class Solution {
public:
    char findTheDifference(string s, string t) {
        int count[26] = {0};
        char ans;
        int sSize = s.size(), tSize = t.size();
        for(int i=0;i<sSize;i++) {
            count[s[i]-'a']++;
        }
        for(int i=0;i<tSize;i++) {
            count[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(count[i]==-1){
                ans = (char)('a'+i);
            }
        }
        return ans;
    }
};