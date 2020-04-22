#include<string>
using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        if(len1==0) return len2;
        if(len2==0) return len1;

        int dp[len1+1][len2+1];

        for(int i=0; i<=len1; i++) dp[i][0] = i;
        for(int j=0; j<=len2; j++) dp[0][j] = j;

        for(int i=1; i<=len1; i++){
            for(int j=1; j<=len2; j++){
                if(word1[i-1]==word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    if(dp[i-1][j-1]<dp[i-1][j]){
                        if(dp[i-1][j-1]<dp[i][j-1]) dp[i][j] = dp[i-1][j-1];
                        else dp[i][j] = dp[i][j-1];
                    }else{
                        if(dp[i-1][j]<dp[i][j-1]) dp[i][j] = dp[i-1][j];
                        else dp[i][j] = dp[i][j-1];
                    }
                    dp[i][j]++;
                }
                
            }
        }
        return dp[len1][len2];

    }
};