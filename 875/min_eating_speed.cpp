#include<vector>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int lo = 1, hi = 1e9, mid;
        while(lo<hi){
            mid = lo + ((hi-lo)>>1);
            int thisTime = 0;
            for(const int &pile: piles){
                thisTime += (pile-1)/mid + 1;
            }
            if(thisTime<=H){
                hi = mid;
            }else{
                lo = mid+1;
            }
        }
        return lo;
    }
};