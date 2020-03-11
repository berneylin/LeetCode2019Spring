class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        return reverseMatch(s, p, 0, 0);
    }

    bool reverseMatch(string &s, string &p, int sIdx, int pIdx) {
        if (pIdx>=p.size()) {
            return sIdx == s.size();
        }
        
        if(pIdx+1 < p.size() && p[pIdx+1] == '*') {
            return reverseMatch(s, p, sIdx, pIdx+2) || ((sIdx < s.size() && (s[sIdx] == p[pIdx] || p[pIdx] == '.')) && reverseMatch(s, p, sIdx+1, pIdx));
        }
        return (sIdx < s.size() && (s[sIdx] == p[pIdx] || p[pIdx] == '.')) && reverseMatch(s, p , sIdx+1, pIdx+1);
    }
};