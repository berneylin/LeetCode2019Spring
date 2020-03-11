class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.size(), pLen = p.size();
        vector<vector<bool> > dp(sLen+1, vector<bool>(pLen+1, false));

        dp[0][0] = true;
        for (int i=2; i<pLen+1; i++) {
            if(p[i-1] == '*')
                dp[0][i] = dp[0][i-2];
        }

        for (int i=1; i<sLen+1; i++) {
            for (int j=1; j<pLen+1; j++) {
                if (s[i-1] == p[j-1]) 
                    dp[i][j] = dp[i-1][j-1];
                else {
                    if (p[j-1] == '.')
                        dp[i][j] = dp[i-1][j-1];
                    else if (p[j-1] == '*'){
                        if (p[j-2] == s[i-1] || p[j-2] == '.')
                            dp[i][j] = dp[i][j-2] || dp[i-1][j];
                        else if(p[j-2] != s[i-1])
                            dp[i][j] = dp[i][j-2];
                    }else {
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[sLen][pLen];
    }
};