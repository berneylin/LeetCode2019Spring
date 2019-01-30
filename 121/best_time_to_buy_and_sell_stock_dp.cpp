class Solution {
public:
    inline int max(int a, int b){
        return a>b?a:b;
    }
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        if(prices.empty()) return 0;
        int minElem = prices[0];
        int pricesSize = prices.size();

        for(int i=1;i<pricesSize;i++){
            if(minElem>prices[i]){
                minElem = prices[i];
            }else{
                ans = max(ans, prices[i]-minElem);
            }
        }
        return ans;
    }
};