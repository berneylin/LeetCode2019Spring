class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        num_days = len(prices)
        K = 2
        dp = [[[0, 0] for k in range(K+1)] for i in range(num_days+1)]

        for i in range(num_days+1):
            dp[i][0][0] = 0
            dp[i][0][1] = float('-inf')

        for k in range(K+1):
            dp[0][k][0] = 0
            dp[0][k][1] = float('-inf')

        for i in range(1, num_days+1):
            for k in reversed(range(1, K+1)):
                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1]+prices[i-1])
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0]-prices[i-1])

        return int(dp[num_days][K][0])