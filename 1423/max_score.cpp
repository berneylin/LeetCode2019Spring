class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int numCards = cardPoints.size();
        int slideWindowSize = numCards - k;

        int totalSum = 0;
        for(const int &num: cardPoints){
            totalSum += num;
        }

        int minSum = totalSum, currSum = 0;
        for(int i=0; i<cardPoints.size(); i++){
            currSum += cardPoints[i];
            if(i>=slideWindowSize)
                currSum -= cardPoints[i-slideWindowSize];
            if(i>=slideWindowSize-1)
                minSum = min(minSum, currSum);                
        }

        return totalSum - minSum;
    }
};