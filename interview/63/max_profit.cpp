#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int numDays = prices.size();
        int dp[numDays+1][2];

        dp[0][0] = 0;
        

        for(int i=1; i<=numDays; i++){
            if(i==1){
                dp[i][0] = 0;
                dp[i][1] = -prices[i-1];
            }
            else {
                dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i-1]);
                dp[i][1] = max(dp[i-1][1], - prices[i-1]);
            }
        }

        return dp[numDays][0];
    }
};