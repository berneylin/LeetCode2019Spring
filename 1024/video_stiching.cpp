#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>> &clips, int T) {
        sort(clips.begin(), clips.end());
        vector<int> dp(100 + 1, INT_MAX);
        dp[0] = 0;
        for (auto clip:clips) {
            int start = clip[0], stop = clip[1];
            if (start > T)
                break;
            for (int i = start; i < stop; i++) {
                if (dp[start] == INT_MAX)
                    return -1;
                dp[i + 1] = min(dp[i + 1], dp[start] + 1);
            }
        }
        if (dp[T] == INT_MAX)
            return -1;
        else
            return dp[T];
    }
};