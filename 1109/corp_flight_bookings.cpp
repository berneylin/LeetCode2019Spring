#include<vector>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> cnt(n, 0);
        for(int i=0; i<bookings.size(); i++){
            int &l = bookings[i][0], &r = bookings[i][1], &c = bookings[i][2];
            cnt[l-1] += c;
            if(r<n) cnt[r] -= c;
        }
        for(int i=1; i<n; i++){
            cnt[i] += cnt[i-1];
        }
        return cnt;
    }
};