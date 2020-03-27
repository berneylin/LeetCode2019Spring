class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        num_days = len(prices)
        dp = [[0, 0] for x in range(num_days+1)]
        
        dp[0][0] = 0.0
        dp[0][1] = float("-inf")

        for i in range(1, num_days+1):
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i-1])
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i-1])

        return int(dp[num_days][0])