class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pricesSize = prices.size();
        int maxProfit = 0;
        for(int i=0;i<pricesSize-1;i++){
            for(int j=i+1;j<pricesSize;j++){
                int thisProfit = prices[j] - prices[i];
                if(thisProfit>0){
                    maxProfit = thisProfit>maxProfit?thisProfit:maxProfit;
                }
            }
        }
        return maxProfit;
    }
};