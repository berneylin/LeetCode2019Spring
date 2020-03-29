class Solution {
public:
    string reverseLeftWords(string s, int n) {
        if(s.empty()) return s;
        for(int i=0; i<s.length()/2; i++){
            char tmpCh = s[i];
            s[i] = s[s.length()-1-i];
            s[s.length()-1-i] = tmpCh;
        }

        for(int i=0; i<(s.length()-n)/2; i++){
            char tmpCh = s[i];
            s[i] = s[(s.length()-n-1)-i];
            s[(s.length()-n-1)-i] = tmpCh;
        }

        for(int i=0; i<n/2; i++){
            char tmpCh = s[s.length()-n+i];
            s[s.length()-n+i] = s[s.length()-1-i];
            s[s.length()-1-i] = tmpCh;
        }

        return s;
    }
};