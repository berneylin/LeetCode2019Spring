class Solution {
public:
    vector<double> twoSum(int n) {
        vector<double> ansVec;
        double baseProb = 1.0/6.0;
        vector<double> dp(n*6+1, 0);  // 色子扔n次最大和为6n
        dp[0] = 1; // base情况
        for(int i=1; i<=n; i++){
            // 更新n次dp数组
            vector<double> tmp(n*6+1, 0);  // 每次在临时数组上做更新
            for(int j=i; j<=6*i; j++){
                // 每次要更新的和:[i, 6i]
                // 掷了i次和为j的可能性为： dp[j-1]*baseProb + dp[j-2] * baseProb + dp[j-3] * baseProb + dp[j-4] * baseProb + dp[j-5] * baseProb + dp[j-6] * baseProb;
                // == baseProb * (dp[j-1]+...+dp[j-6])
                // 如果j-k不可达？则概率为0
                for(int k=1; k<=j && k<=6; k++){
                    tmp[j] += dp[j-k]*baseProb;
                }
            }
            dp = tmp; // 更新dp数组
        }
        
        for(int i=n; i<=6*n; i++){
            ansVec.push_back(dp[i]);
        }

        return ansVec;
    }
};