class Solution {
public:
    inline int min(int x, int y){
        return x<y?x:y;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int costSize = cost.size();
        if(costSize==0) return 0;
        else if(costSize==1) return cost[0];
        else if(costSize==2) return min(cost[0], cost[1]);
        int dp[costSize] = {cost[0], cost[1]};
        for(int i=2;i<costSize;i++){
            dp[i] = min(dp[i-1]+cost[i], dp[i-2]+cost[i]);
        }
        return min(dp[costSize-1], dp[costSize-2]);
    }
};