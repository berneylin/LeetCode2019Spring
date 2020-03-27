class Solution:
    def maxProfit(self, K: int, prices: List[int]) -> int:
        num_days = len(prices)
        ans = None
        if K <= num_days//2:
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

            ans = dp[num_days][K][0]
        else:
            dp = [[0, 0] for i in range(num_days+1)]

            dp[0][0] = 0.0
            dp[0][1] = float('-inf')

            for i in range(1, num_days+1):
                dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i-1])
                dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i-1])
            
            ans = dp[num_days][0]

        return int(ans)